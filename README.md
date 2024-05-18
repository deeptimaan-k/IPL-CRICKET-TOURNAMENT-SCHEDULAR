# IPL Cricket Tournament Scheduler

This project is an IPL Cricket Tournament Scheduler written in C. It allows you to manage teams, view schedules, and modify team information. The program uses a text file to store team records and provides a simple menu-driven interface for various operations.

## Features

- **Add Team**: Add a new team to the tournament.
- **View Team**: View the list of all teams participating in the tournament.
- **View Schedule**: Generate and view the match schedule.
- **Modify Team**: Replace an existing team with a new team.
- **Delete Team**: Remove a team from the tournament.
- **Color-coded Output**: Different sections of the program output are color-coded for better readability.

## Getting Started

### Prerequisites

To compile and run this project, you need:
- A C compiler (e.g., GCC)
- A Windows environment (for `gotoxy` function and color codes)

### Installation

1. **Clone the repository**:
    ```sh
    git clone https://github.com/yourusername/ipl-cricket-tournament-scheduler.git
    ```
2. **Navigate to the project directory**:
    ```sh
    cd ipl-cricket-tournament-scheduler
    ```

### Usage

1. **Compile the program**:
    ```sh
    gcc main.c -o scheduler
    ```
2. **Run the program**:
    ```sh
    scheduler.exe
    ```

### File Structure

- `main.c`: The main source code file containing all functions and logic.
- `record.txt`: The text file used to store team names.

### Functions

- **`gotoxy(int x, int y)`**: Set the cursor position on the console.
- **`menu()`**: Display the main menu.
- **`add()`**: Add a new team to the record.
- **`view()`**: View all teams in the record.
- **`Schedule()`**: Generate and display the match schedule.
- **`modify()`**: Replace an existing team with a new team.
- **`deleterec()`**: Delete a team from the record.
- **`replaceAll(char *str, const char *oldWord, const char *newWord)`**: Replace all occurrences of a word in a string.
- **`len()`**: Get the number of teams in the record.
- **`free_array(char* a[30])`**: Free dynamically allocated memory for team names.
- **Color Functions**: Set the console text color (`red()`, `yellow()`, `green()`, `cyan()`, `reset()`).

### Contribution

Feel free to contribute to this project by opening issues or submitting pull requests.

### License

This project is licensed under the MIT License.

### Contact

For any questions or suggestions, please contact:

- Your Name: [Deeptimaan K. Jadaun](mailto:deeptimaankrishnajadaun@gmail.com)
- GitHub: [deeptimaan-k](https://github.com/deeptimaan-k)

---

**Note**: This project is designed for educational purposes and may require modifications to run on non-Windows systems or to fit specific use cases.
