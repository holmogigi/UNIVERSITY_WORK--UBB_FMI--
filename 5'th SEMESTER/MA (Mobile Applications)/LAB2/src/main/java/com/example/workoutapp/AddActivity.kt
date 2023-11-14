package com.example.workoutapp

import android.app.Activity
import android.content.Intent
import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.example.workoutapp.databinding.ActivityAddBinding

class AddActivity : AppCompatActivity() {

    private lateinit var binding: ActivityAddBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityAddBinding.inflate(layoutInflater)
        setContentView(binding.root)

        binding.btnAddTodo.setOnClickListener {
            val todoTitle = binding.etTodoTitle.text.toString()
            val todoSets = binding.etTodoSets.text.toString().toInt()
            val todoReps = binding.etTodoReps.text.toString().toInt()
            val todoRestTime = binding.etTodoRestTime.text.toString().toInt()

            if(todoTitle.isNotEmpty() && todoSets > 0 && todoReps > 0 && todoRestTime > 0) {
                val intent = Intent()
                intent.putExtra("TODO_TITLE", todoTitle)
                intent.putExtra("TODO_SETS", todoSets)
                intent.putExtra("TODO_REPS", todoReps)
                intent.putExtra("TODO_RESTTIME", todoRestTime)
                setResult(Activity.RESULT_OK, intent)
                finish()
            }
        }
    }
}