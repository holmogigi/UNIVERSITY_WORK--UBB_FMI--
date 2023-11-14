package com.example.workoutapp

import android.app.Activity
import android.app.AlertDialog
import android.content.Intent
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Toolbar
import androidx.recyclerview.widget.LinearLayoutManager
import com.example.workoutapp.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var todoAdapter: TodoAdapter
    private val todos = mutableListOf<Todo>()

    companion object {
        const val ADD_TODO_REQUEST_CODE = 1
        const val EDIT_TODO_REQUEST_CODE = 2
    }

    override fun onCreate(savedInstanceState: Bundle?) {

        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        val toolbar: androidx.appcompat.widget.Toolbar = findViewById(R.id.toolbar)
        setSupportActionBar(toolbar)
        supportActionBar?.setDisplayShowTitleEnabled(false)

        todoAdapter = TodoAdapter(todos)

        binding.rvTodoItems.adapter = todoAdapter
        binding.rvTodoItems.layoutManager = LinearLayoutManager(this)


        binding.btnAddTodo.setOnClickListener {
            val intent = Intent(this, AddActivity::class.java)
            startActivityForResult(intent, ADD_TODO_REQUEST_CODE)
        }

        binding.btnEditTodo.setOnClickListener {
            val checkedTodo = todos.find { it.isChecked }
            if (checkedTodo != null) {
                val intent = Intent(this, EditActivity::class.java)
                intent.putExtra("TODO_TITLE", checkedTodo.title)
                intent.putExtra("TODO_SETS", checkedTodo.sets)
                intent.putExtra("TODO_REPS", checkedTodo.reps)
                intent.putExtra("TODO_RESTTIME", checkedTodo.resttime)
                startActivityForResult(intent, EDIT_TODO_REQUEST_CODE)
            }
        }

        binding.btnDeleteDoneTodos.setOnClickListener {
            AlertDialog.Builder(this)
                .setTitle("Delete exercise")
                .setMessage("Are you sure you want to delete this exercise?")
                .setPositiveButton("Yes") { _, _ ->
                    todoAdapter.deleteDoneTodos()
                }
                .setNegativeButton("No", null)
                .show()
        }
    }

    override fun onActivityResult(requestCode: Int, resultCode: Int, data: Intent?) {
        super.onActivityResult(requestCode, resultCode, data)

        if (requestCode == ADD_TODO_REQUEST_CODE && resultCode == Activity.RESULT_OK) {
            data?.let { intent ->
                val todoTitle = intent.getStringExtra("TODO_TITLE")
                val todoSets = intent.getIntExtra("TODO_SETS", 0)
                val todoReps = intent.getIntExtra("TODO_REPS", 0)
                val todoRestTime = intent.getIntExtra("TODO_RESTTIME", 0)

                if (todoTitle != null) {
                    val todo = Todo(todoTitle, todoSets, todoReps, todoRestTime)
                    todoAdapter.addTodo(todo)
                }
            }
        }

        if (requestCode == EDIT_TODO_REQUEST_CODE && resultCode == Activity.RESULT_OK) {
            data?.let { intent ->
                val todoTitle = intent.getStringExtra("TODO_TITLE")
                val todoSets = intent.getIntExtra("TODO_SETS", 0)
                val todoReps = intent.getIntExtra("TODO_REPS", 0)
                val todoRestTime = intent.getIntExtra("TODO_RESTTIME", 0)

                if (todoTitle != null) {
                    val todo = todos.find { it.isChecked }
                    if (todo != null) {
                        todo.title = todoTitle
                        todo.sets = todoSets
                        todo.reps = todoReps
                        todo.resttime = todoRestTime
                        todoAdapter.notifyDataSetChanged()
                    }
                }
            }
        }
    }
}
