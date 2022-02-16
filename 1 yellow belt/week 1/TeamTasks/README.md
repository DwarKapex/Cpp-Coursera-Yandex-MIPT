# Desctiption

Implement the Team Tasks class, which allows you to store statistics on the statuses of the tasks of the development team:

```c++
// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const string& person) const;
  
  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const string& person);
  
  // Обновить статусы по данному количеству задач конкретного разработчика,
  // подробности см. ниже
  tuple<TasksInfo, TasksInfo> PerformPersonTasks(
      const string& person, int task_count);
};
```

The PerformPersonTasks method should implement the following algorithm:

- Consider all the outstanding tasks of the person developer.

 - Let's sort them by statuses: first, all tasks with the NEW status, then all tasks with the IN_PROGRESS status, and finally tasks with the TESTING status.

 - Let's consider the first task_count tasks and transfer each of them to the following status in accordance with the natural order: NEW → IN_PROGRESS → TESTING → DONE.

 - We will return a tuple of two elements: information about the statuses of the updated tasks (including those that turned out to be in the DONE status) and information about the statuses of the remaining outstanding tasks.

If there is no developer named person, the PerformPersonTasks method should return a tuple of two empty TasksInfo

It is guaranteed that task_count is a positive number. If task_count exceeds the current number of outstanding tasks of the developer, it is enough to assume that task_count is equal to the number of outstanding tasks: in this case, you do not need to update the status of any task twice.

In addition, it is guaranteed that the GetPersonTasksInfo method will not be called for a developer who has no tasks.

## Example of the work of the PerformPersonTasks method
Let's assume that a particular developer has 10 tasks with the following statuses:

```
NEW — 3
IN_PROGRESS — 2
TESTING — 4
DONE — 1
```

The PerformPersonTasks command arrives with the task_count = 4 parameter, which means updating the status for 3 tasks from NEW to IN_PROGRESS and for 1 task from IN_PROGRESS to TESTING. 
If you write out the statuses of all tasks in order, and put the updated ones in square brackets, then the change can be depicted as follows:

  [NEW, NEW, NEW, IN_PROGRESS,] IN_PROGRESS, TESTING, TESTING, TESTING, TESTING, DONE

  ==>

  [IN_PROGRESS, IN_PROGRESS, IN_PROGRESS, TESTING,] IN_PROGRESS, TESTING, TESTING, TESTING, TESTING, DONE

Thus, the new task statuses will be as follows:

```
IN_PROGRESS — 3 updated, 1 old
TESTING — 1 updated, 4 old
DONE — 1 old
```

In this case, you need to return a tuple of 2 dictionaries:

Updated tasks: IN_PROGRESS - 3, TESTING - 1.

Non-updated tasks, excluding completed ones: IN_PROGRESS - 1, TESTING - 4.

None of the dictionaries should contain unnecessary elements, that is, statuses that correspond to zero tasks.

By convention, DONE tasks do not need to be returned in unpowered tasks (untouched_tasks).

## Note
Updating the dictionary at the same time as iterating on it can lead to unpredictable consequences. If such a need arises, it is recommended to first collect information about updates in a separate temporary dictionary, and then apply them to the main dictionary.

## Code example
```c++
// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
  cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");
  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }
  cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
  
  TasksInfo updated_tasks, untouched_tasks;
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);
  
  tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
  cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
```

## Output

```
Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done
```