package com.rbodai.fractions

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.KeyEvent
import android.view.inputmethod.EditorInfo
import android.widget.EditText
import android.widget.TextView
import androidx.appcompat.app.AlertDialog

class MainActivity : AppCompatActivity() {

    companion object {
        init {
            System.loadLibrary("fractional");
        }
    }

    external fun produceFractionalResult(fractional: String): String

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val outputText = findViewById<TextView>(R.id.outputText)
        val inputText = findViewById<EditText>(R.id.inputText)

        inputText.setOnEditorActionListener { _, actionId, event ->
            if (actionId == EditorInfo.IME_ACTION_SEND ||
                (event?.keyCode == KeyEvent.KEYCODE_ENTER && event.action == KeyEvent.ACTION_DOWN)) {
                try {
                    val input = inputText.text.toString()
                    val output = produceFractionalResult(input)
                    outputText.append("? $input\n= $output\n\n")
                    inputText.text.clear()
                }
                catch (exception: java.lang.RuntimeException) {
                    showMessage(exception.message!!)
                }
                catch (exception: java.lang.IllegalArgumentException) {
                    showMessage(exception.message!!)
                }
                true
            } else {
                false
            }
        }
    }

    fun showMessage(message: String) {
        AlertDialog.Builder(this)
            .setTitle("Invalid input")
            .setMessage(message)
            .setIcon(android.R.drawable.ic_dialog_alert)
            .show()
    }
}