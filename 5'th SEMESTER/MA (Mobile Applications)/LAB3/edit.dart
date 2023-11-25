import 'package:flutter/material.dart';
import 'package:workoutbuddy/model.dart';

class EditActivity extends StatefulWidget {
  final Todo todo;

  EditActivity({required this.todo});

  @override
  _EditActivityState createState() => _EditActivityState();
}

class _EditActivityState extends State<EditActivity> {
  final TextEditingController titleController = TextEditingController();
  final TextEditingController setsController = TextEditingController();
  final TextEditingController repsController = TextEditingController();
  final TextEditingController resttimeController = TextEditingController();

  @override
  void initState() {
    super.initState();
    titleController.text = widget.todo.title;
    setsController.text = widget.todo.sets.toString();
    repsController.text = widget.todo.reps.toString();
    resttimeController.text = widget.todo.resttime.toString();
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
                if (titleController.text.isNotEmpty &&
                    int.parse(setsController.text) > 0 &&
                    int.parse(repsController.text) > 0 &&
                    int.parse(resttimeController.text) > 0) {
                  Navigator.pop(
                    context,
                    Todo(
                      title: titleController.text,
                      sets: int.parse(setsController.text),
                      reps: int.parse(repsController.text),
                      resttime: int.parse(resttimeController.text),
                    ),
                  );
                }
              },
              child: Text('Edit Exercise'),
            ),
          ],
        ),
      ),
    );
  }
}
