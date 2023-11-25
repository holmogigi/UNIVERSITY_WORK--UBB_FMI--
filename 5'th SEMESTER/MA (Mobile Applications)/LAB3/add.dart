import 'package:flutter/material.dart';
import 'package:workoutbuddy/model.dart';

class AddActivity extends StatefulWidget {
  @override
  _AddActivityState createState() => _AddActivityState();
}

class _AddActivityState extends State<AddActivity> {
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
              child: Text('Add Exercise'),
            ),
          ],
        ),
      ),
    );
  }
}
