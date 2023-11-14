package com.example.workoutapp

import android.graphics.Color
import android.graphics.Paint.STRIKE_THRU_TEXT_FLAG
import android.view.LayoutInflater
import android.view.ViewGroup
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView
import com.example.workoutapp.databinding.ItemBinding

class TodoAdapter(private val todos: MutableList<Todo>) : RecyclerView.Adapter<TodoAdapter.TodoViewHolder>()
{

    class TodoViewHolder(val binding: ItemBinding) : RecyclerView.ViewHolder(binding.root)

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): TodoViewHolder {
        val binding = ItemBinding.inflate(LayoutInflater.from(parent.context), parent, false)
        return TodoViewHolder(binding)
    }

    fun addTodo(todo: Todo) {
        todos.add(todo)
        notifyItemInserted(todos.size - 1)
    }

    fun deleteDoneTodos() {
        todos.removeAll { todo ->
            todo.isChecked
        }
        notifyDataSetChanged()
    }

    private fun toggleStrikeThrough(tvTodoTitle: TextView, isChecked: Boolean) {
        if(isChecked) {
            tvTodoTitle.paintFlags = tvTodoTitle.paintFlags or STRIKE_THRU_TEXT_FLAG
        } else {
            tvTodoTitle.paintFlags = tvTodoTitle.paintFlags and STRIKE_THRU_TEXT_FLAG.inv()
        }
    }

    override fun onBindViewHolder(holder: TodoViewHolder, position: Int) {
        val curTodo = todos[position]
        holder.binding.apply {
            tvTodoTitle.text = curTodo.title
            tvTodoSets.text = "Sets: ${curTodo.sets}"
            tvTodoReps.text = "Reps: ${curTodo.reps}"
            tvTodoRestTime.text = "Rest Time: ${curTodo.resttime}"

            cbDone.setOnCheckedChangeListener(null)
            cbDone.isChecked = curTodo.isChecked

            // Set the color based on whether the item is checked
            if (curTodo.isChecked) {
                root.setBackgroundColor(Color.LTGRAY)
            } else {
                root.setBackgroundColor(Color.WHITE)
            }

            cbDone.setOnCheckedChangeListener { _, isChecked ->
                if (isChecked) {
                    for (todo in todos) {
                        todo.isChecked = false
                    }
                    curTodo.isChecked = true
                } else {
                    curTodo.isChecked = false
                }
                holder.itemView.post {
                    notifyDataSetChanged()
                }
            }
        }
    }

    override fun getItemCount(): Int {
        return todos.size
    }
}