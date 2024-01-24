import 'package:flutter/material.dart';
import 'package:workoutbuddy/model.dart';
import 'package:sqflite/sqflite.dart';
import 'package:path/path.dart';
import 'package:sqflite_common/sqlite_api.dart';

void main() {
  runApp(MaterialApp(
    home: MainActivity(),
  ));
}

class MainActivity extends StatefulWidget {
  @override
  _MainActivityState createState() => _MainActivityState();
}

class _MainActivityState extends State<MainActivity> {
  Database? db;
  List<Todo> todos = [];

  @override
  void initState() {
    super.initState();
    initDatabase();
  }

  Future<void> initDatabase() async {
    db = await openDatabase(
      join(await getDatabasesPath(), 'todos.db'),
      onCreate: (db, version) {
        return db.execute(
          "CREATE TABLE todos(id INTEGER PRIMARY KEY, title TEXT, sets INTEGER, reps INTEGER, resttime INTEGER, isChecked INTEGER)",
        );
      },
      version: 1,
    );
    fetchTodos();
  }

  Future<void> fetchTodos() async {
    final List<Map<String, dynamic>> maps = await db!.query('todos');
    setState(() {
      todos = List.generate(maps.length, (i) {
        return Todo.fromMap(maps[i]);
      });
    });
  }

  Future<void> addTodo(Todo todo) async {
    await db!.insert(
      'todos',
      todo.toMap(),
      conflictAlgorithm: ConflictAlgorithm.replace,
    );
    fetchTodos();
  }

  Future<void> deleteDoneTodos() async {
    await db!.delete(
      'todos',
      where: "isChecked = ?",
      whereArgs: [1],
    );
    fetchTodos();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('WorkoutBuddy'),
      ),
      body: ListView.builder(
        itemCount: todos.length,
        itemBuilder: (context, index) {
          return ListTile(
            title: Text(todos[index].title),
            subtitle: Text(
                '${todos[index].sets} sets, ${todos[index].reps} reps, ${todos[index].resttime} seconds rest'),
            trailing: Checkbox(
              value: todos[index].isChecked,
              onChanged: (bool? value) {
                setState(() {
                  for (var todo in todos) {
                    todo.isChecked = false;
                  }
                  todos[index].isChecked = value!;
                });
              },
            ),
          );
        },
      ),
      floatingActionButton: FloatingActionButton(
        onPressed: () {
          // Navigate to AddActivity and get a result back
          Navigator.push(
            context,
            MaterialPageRoute(builder: (context) => AddActivity()),
          ).then((result) {
            if (result != null) {
              addTodo(result);
            }
          });
        },
        child: Icon(Icons.add),
      ),
      floatingActionButtonLocation: FloatingActionButtonLocation.centerDocked,
bottomNavigationBar: BottomAppBar(
  shape: CircularNotchedRectangle(),
  notchMargin: 4.0,
  child: Row(
    mainAxisSize: MainAxisSize.max,
    mainAxisAlignment: MainAxisAlignment.spaceBetween,
    children: <Widget>[
      IconButton(
        icon: Icon(Icons.delete),
        onPressed: () {
          showDialog(
            context: context,
            builder: (BuildContext context) {
              return AlertDialog(
                title: Text('Delete exercise'),
                content: Text('Are you sure you want to delete this exercise?'),
                actions: <Widget>[
                  TextButton(
                    child: Text('Yes'),
                    onPressed: () async {
                      try {
                        await deleteDoneTodos();
                        Navigator.of(context).pop();
                      } catch (e) {
                        ScaffoldMessenger.of(context).showSnackBar(
                          SnackBar(
                            content: Text('An error occurred: $e'),
                          ),
                        );
                      }
                    },
                  ),
                  TextButton(
                    child: Text('No'),
                    onPressed: () {
                      Navigator.of(context).pop();
                    },
                  ),
                ],
              );
            },
          );
        },
      ),
    ],
  ),
),
            IconButton(
              icon: Icon(Icons.edit),
              onPressed: () async {
                // Find the checked Todo
                Todo checkedTodo = todos.firstWhere((todo) => todo.isChecked,
                    orElse: () =>
                        Todo(title: 'Default', sets: 0, reps: 0, resttime: 0));
                // ignore: unnecessary_null_comparison
                if (checkedTodo.title != 'Default') {
                  // Navigate to EditActivity and get a result back
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => EditActivity(
                        todo: checkedTodo,
                        updateTodo: (updatedTodo) async {
                          if (db != null) {
                            await db!.update(
                              'todos',
                              updatedTodo.toMap(),
                              where: "id = ?",
                              whereArgs: [updatedTodo.id],
                            );
                          }
                          fetchTodos();
                        },
                      ),
                    ),
                  );
                }
              },
            ),
          ],
        ),
      ),
    );
  }
}

class AddActivity extends StatelessWidget {
  final TextEditingController titleController = TextEditingController();
  final TextEditingController setsController = TextEditingController();
  final TextEditingController repsController = TextEditingController();
  final TextEditingController resttimeController = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Add Exercise'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(8.0),
        child: Column(
          children: <Widget>[
            TextField(
              controller: titleController,
              decoration: InputDecoration(labelText: 'Title'),
            ),
            TextField(
              controller: setsController,
              decoration: InputDecoration(labelText: 'Sets'),
              keyboardType: TextInputType.number,
            ),
            TextField(
              controller: repsController,
              decoration: InputDecoration(labelText: 'Reps'),
              keyboardType: TextInputType.number,
            ),
            TextField(
              controller: resttimeController,
              decoration: InputDecoration(labelText: 'Rest Time'),
              keyboardType: TextInputType.number,
            ),
            ElevatedButton(
              onPressed: () {
                Navigator.pop(
                  context,
                  Todo(
                    title: titleController.text,
                    sets: int.parse(setsController.text),
                    reps: int.parse(repsController.text),
                    resttime: int.parse(resttimeController.text),
                  ),
                );
              },
              child: Text('Add Exercise'),
            ),
          ],
        ),
      ),
    );
  }
}

class EditActivity extends StatelessWidget {
  final Todo todo;
  final Function(Todo) updateTodo;
  final TextEditingController titleController = TextEditingController();
  final TextEditingController setsController = TextEditingController();
  final TextEditingController repsController = TextEditingController();
  final TextEditingController resttimeController = TextEditingController();

  EditActivity({required this.todo, required this.updateTodo}) {
    titleController.text = todo.title;
    setsController.text = todo.sets.toString();
    repsController.text = todo.reps.toString();
    resttimeController.text = todo.resttime.toString();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text('Edit Exercise'),
      ),
      body: Padding(
        padding: const EdgeInsets.all(8.0),
        child: Column(
          children: <Widget>[
            TextField(
              controller: titleController,
              decoration: InputDecoration(labelText: 'Title'),
            ),
            TextField(
              controller: setsController,
              decoration: InputDecoration(labelText: 'Sets'),
              keyboardType: TextInputType.number,
            ),
            TextField(
              controller: repsController,
              decoration: InputDecoration(labelText: 'Reps'),
              keyboardType: TextInputType.number,
            ),
            TextField(
              controller: resttimeController,
              decoration: InputDecoration(labelText: 'Rest Time'),
              keyboardType: TextInputType.number,
            ),
            ElevatedButton(
              onPressed: () {
                Todo updatedTodo = Todo(
                  id: todo.id,
                  title: titleController.text,
                  sets: int.parse(setsController.text),
                  reps: int.parse(repsController.text),
                  resttime: int.parse(resttimeController.text),
                  isChecked: todo.isChecked,
                );
                Navigator.pop(context, updatedTodo);
                updateTodo(updatedTodo);
              },
              child: Text('Edit Exercise'),
            ),
          ],
        ),
      ),
    );
  }
}
