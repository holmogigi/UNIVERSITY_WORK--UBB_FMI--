package com.example.workoutapp

data class Todo(
    var title: String,
    var sets: Int,
    var reps: Int,
    var resttime: Int,
    var isChecked: Boolean = false
)