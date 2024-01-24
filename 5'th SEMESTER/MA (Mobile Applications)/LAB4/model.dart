import 'package:sqflite/sqflite.dart';

class Todo {
  int? id;
  String title;
  int sets;
  int reps;
  int resttime;
  bool isChecked;

  Todo({
    this.id,
    required this.title,
    required this.sets,
    required this.reps,
    required this.resttime,
    this.isChecked = false,
  });

  // Convert a Todo object into a Map object
  Map<String, dynamic> toMap() {
    return {
      'id': id,
      'title': title,
      'sets': sets,
      'reps': reps,
      'resttime': resttime,
      'isChecked': isChecked ? 1 : 0,
    };
  }

  // Extract a Todo object from a Map object
  factory Todo.fromMap(Map<String, dynamic> map) {
    return Todo(
      id: map['id'],
      title: map['title'],
      sets: map['sets'],
      reps: map['reps'],
      resttime: map['resttime'],
      isChecked: map['isChecked'] == 1,
    );
  }
}
