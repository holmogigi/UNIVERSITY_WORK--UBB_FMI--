import 'package:flutter/material.dart';
import 'package:workoutbuddy/model.dart';

class TodoAdapter extends StatefulWidget {
  final List<Todo> todos;

  TodoAdapter({required this.todos});

  @override
  _TodoAdapterState createState() => _TodoAdapterState();
}

class _TodoAdapterState extends State<TodoAdapter> {
  void addTodo(Todo todo) {
    setState(() {
      widget.todos.add(todo);
    });
  }

  void deleteDoneTodos() {
    setState(() {
      widget.todos.removeWhere((todo) => todo.isChecked);
    });
  }

  @override
  Widget build(BuildContext context) {
    return ListView.builder(
      itemCount: widget.todos.length,
      itemBuilder: (context, index) {
        return ListTile(
          title: Text(widget.todos[index].title),
          subtitle: Text(
              '${widget.todos[index].sets} sets, ${widget.todos[index].reps} reps, ${widget.todos[index].resttime} seconds rest'),
          trailing: Checkbox(
            value: widget.todos[index].isChecked,
            onChanged: (bool? value) {
              setState(() {
                for (var todo in widget.todos) {
                  todo.isChecked = false;
                }
                widget.todos[index].isChecked = value!;
              });
            },
          ),
        );
      },
    );
  }
}
