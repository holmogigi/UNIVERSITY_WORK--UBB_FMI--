# 💻 Assignment 06 - 08
## Requirements
- You will solve one of the problems below using simple feature-driven development
- Your program must provide a menu-driven console-based user interface. Implementation details are up to you
- Implementation must employ layered architecture and classes

### For week 8 (25% of grade)
- Implement features 1 and 2
- Have at least 20 procedurally generated items in your application at startup
- Provide specification and tests for all non-UI classes and methods for the first functionality
- Implement and use your own exception classes.

### For week 9 (25% of grade)
- Implement features 3 and 4
- Implement **PyUnit test cases**

### For week 10 (50% of grade)
- All features must be implemented

## Bonus possibility (0.1p, deadline week 10)
- 95% unit test code coverage for all modules except the UI (use *PyCharm Professional*, the *[coverage](https://coverage.readthedocs.io/en/coverage-5.3/)* or other modules)

## Bonus possibility (0.2p, deadline week 10)
- Implement a graphical user interface, in addition to the required menu-driven UI. Program can be started with either UI, without changing the source code.

### 5. Activity Planner
The following information is stored in a personal activity planner:
- **Person**: `person_id`, `name`, `phone_number`
- **Activity**: `activity_id`, `person_id` - list, `date`, `time`, `description`

Create an application to:
1. Manage persons and activities. The user can add, remove, update, and list both persons and activities.
2. Add/remove activities. Each activity can be performed together with one or several other persons, who are already in the user’s planner. Activities must not overlap (user cannot have more than one activity at a given time).
3. Search for persons or activities. Persons can be searched for using name or phone number. Activities can be searched for using date/time or description. The search must work using case-insensitive, partial string matching, and must return all matching items.
4. Create statistics:
    - Activities for a given date. List the activities for a given date, in the order of their start time.
    - Busiest days. This will provide the list of upcoming dates with activities, sorted in ascending order of the free time in that day (all intervals with no activities).
    - Activities with a given person. List all upcoming activities to which a given person will participate.
5. Unlimited undo/redo functionality. Each step will undo/redo the previous operation performed by the user. Undo/redo operations must cascade and have a memory-efficient implementation (no superfluous list copying).
