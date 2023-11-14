UI Interface only

Read operation is implemented in a list

A recycler view is used linked to a view model using a live view object. Or the activity/fragment is marshaling only the affected object/operation. No rebuild of the list/adapter or activity/fragment.


Create operation

Only the created element is added in the list. The create operation is maintained is a separate activity/fragment. All the main fields are available to be set. The create view/form has labels for each input field. If we have validation errors the errors are handled in this view.


Update operation

Only the updated element is passed back to the list. The element is properly identified. The update operation is maintained in a separate activity/fragment. All the main fields are available to be updated. The update view/form has labels for each input field and the existing values are pre-populated. If we have validation errors the errors are handled in this view.


Delete operation

Only the id of the removed element is passed back to the list. The element is properly identified. A confirmation dialog is used.


GitHub

The GitHub repository link is added to the assignment. Only the sources were added in the repo, no build directory.
