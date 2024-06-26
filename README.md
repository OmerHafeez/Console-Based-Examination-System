This project implements a quiz system using C++ classes for managing teachers and students, along with quiz functionalities. The system allows teachers to create quizzes and students to participate in them.

Features
Teacher Class: Manages teacher information including name, subject, email, and login functionality.
Student Class: Stores student information such as name, roll number, course registrations, and login capabilities.
Quiz Classes: Includes classes for different types of quiz questions (MCQs, True/False, Subjective).
File Handling: Reads quiz questions and answers from external files.
Password Validation: Implements password validation for both teachers and students.
Classes
Teacher
The Teacher class manages teacher information and functionalities.

Attributes:
name: Name of the teacher.
subject: Subject taught by the teacher.
email: Automatically generated email based on the name.
password: Password for login.
Methods:
setName(): Sets the name of the teacher.
setSubject(): Sets the subject taught.
setEmail(): Generates the email based on the name.
login(): Validates teacher login credentials.
makequiz(): Allows the teacher to create quizzes.
Student
The Student class manages student information and course registrations.

Attributes:
rollno: Student's roll number.
name: Student's name.
email: Automatically generated email based on the roll number.
password: Password for login.
Various course registration flags (CS101, CS201, etc.).
Methods:
setRollno(): Sets the student's roll number.
setName(): Sets the student's name.
setCSXXX(): Sets the registration status for each course.
setEmail(): Generates the email based on the roll number.
login(): Validates student login credentials.
course_offering(): Displays available courses.
course_registered(): Displays registered courses.
Quiz Classes
Include classes like MCQs, TrueFalse, and Subjective for handling different types of quiz questions.

SetEmail
Utility class for password validation and email generation.

Usage
Clone the repository.
Compile the program using a C++ compiler.
Run the executable.
Follow on-screen instructions for teachers and students.
