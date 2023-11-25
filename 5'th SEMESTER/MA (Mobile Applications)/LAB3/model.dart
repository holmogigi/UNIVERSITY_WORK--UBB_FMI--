class Todo {
  String title;
  int sets;
  int reps;
  int resttime;
  bool isChecked;

  Todo({
    required this.title,
    required this.sets,
    required this.reps,
    required this.resttime,
    this.isChecked = false,
  });
}
