import 'package:flutter/material.dart';
import 'package:workoutbuddy/model.dart';

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
  final List<Todo> todos = [];

  void addTodo(Todo todo) {
    setState(() {
      todos.add(todo);
    });
  }

  void deleteDoneTodos() {
    setState(() {
      todos.removeWhere((todo) => todo.isChecked);
    });
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
                      content: Text(
                          'Are you sure you want to delete this exercise?'),
                      actions: <Widget>[
                        TextButton(
                          child: Text('Yes'),
                          onPressed: () {
                            deleteDoneTodos();
                            Navigator.of(context).pop();
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
            IconButton(
              icon: Icon(Icons.edit),
              onPressed: () {
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
                        builder: (context) => EditActivity(todo: checkedTodo)),
                  ).then((result) {
                    if (result != null) {
                      setState(() {
                        checkedTodo.title = result.title;
                        checkedTodo.sets = result.sets;
                        checkedTodo.reps = result.reps;
                        checkedTodo.resttime = result.resttime;
                      });
                    }
                  });
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
  final TextEditingController titleController = TextEditingController();
  final TextEditingController setsController = TextEditingController();
  final TextEditingController repsController = TextEditingController();
  final TextEditingController resttimeController = TextEditingController();

  EditActivity({required this.todo}) {
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
              child: Text('Edit Exercise'),
            ),
          ],
        ),
      ),
    );
  }
}
