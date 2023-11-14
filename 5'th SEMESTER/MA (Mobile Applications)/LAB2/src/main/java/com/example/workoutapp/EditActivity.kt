package com.example.workoutapp

import android.app.Activity
import android.content.Intent
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.workoutapp.databinding.ActivityEditBinding

class EditActivity : AppCompatActivity() {

    private lateinit var binding: ActivityEditBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityEditBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Get the current todo details from the intent
        val todoTitle = intent.getStringExtra("TODO_TITLE")
        val todoSets = intent.getIntExtra("TODO_SETS", 0)
        val todoReps = intent.getIntExtra("TODO_REPS", 0)
        val todoRestTime = intent.getIntExtra("TODO_RESTTIME", 0)

        // Set the current todo details in the EditText fields
        binding.etTodoTitle.setText(todoTitle)
        binding.etTodoSets.setText(todoSets.toString())
        binding.etTodoReps.setText(todoReps.toString())
        binding.etTodoRestTime.setText(todoRestTime.toString())

        binding.btnEditTodo.setOnClickListener {
            val newTodoTitle = binding.etTodoTitle.text.toString()
            val newTodoSets = binding.etTodoSets.text.toString().toInt()
            val newTodoReps = binding.etTodoReps.text.toString().toInt()
            val newTodoRestTime = binding.etTodoRestTime.text.toString().toInt()

            if(newTodoTitle.isNotEmpty() && newTodoSets > 0 && newTodoReps > 0 && newTodoRestTime > 0) {
                val intent = Intent()
                intent.putExtra("TODO_TITLE", newTodoTitle)
                intent.putExtra("TODO_SETS", newTodoSets)
                intent.putExtra("TODO_REPS", newTodoReps)
                intent.putExtra("TODO_RESTTIME", newTodoRestTime)
                setResult(Activity.RESULT_OK, intent)
                finish()
            }
        }
    }
}