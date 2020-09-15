#include<iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::~LinkedList()
{
	DestructorHelper(head);
	head = nullptr;
}

void LinkedList::DestructorHelper(Course * cursor)
{
	if (cursor == nullptr)
		return;
	else {
		DestructorHelper(cursor->next);
		delete cursor;
	}
}


int LinkedList::Size() const
{
	int size = SizeHelper(head);
	return size;
}
int LinkedList::SizeHelper(Course const * cursor) const
{
	if (cursor == nullptr)
		return 0;
	else 
		return 1 + SizeHelper(cursor->next);
}

void LinkedList::Insert(Course const & newCourse)
{
	InsertHelper(head, newCourse);
}
void LinkedList::InsertHelper(Course *& head, Course const & newCourse)
{
	if (head == nullptr || head->courseNumber >= newCourse.courseNumber) {
		Course *temp = new Course(newCourse.courseNumber, newCourse.courseName, newCourse.credits, newCourse.grade);
		temp->next = head;
		head = temp;
	}
	else
		InsertHelper(head->next, newCourse);
}

double LinkedList::CalculateGPA() const
{
	double gpa = (CalculateTotalGradePoints(head)) / CalculateTotalCredits(head);
	return gpa;
}
double LinkedList::CalculateTotalGradePoints(Course const * cursor) const
{
	if (cursor == nullptr)
		return 0.0;
	else 
		return cursor->grade * cursor->credits + CalculateTotalGradePoints(cursor->next);
}
unsigned int LinkedList::CalculateTotalCredits(Course const * cursor) const
{
	if (cursor == nullptr)
		return 0;
	else
		return cursor->credits + CalculateTotalCredits(cursor->next);
}

void LinkedList::PrintList() const
{
	cout << "Size of the list is: " << Size() << endl;
	PrintListHelper(head);
	cout << endl;
}
void LinkedList::PrintListHelper(Course const * cursor) const
{
	if (cursor == nullptr)
		return;
	else {
		cout << "cs" << cursor->courseNumber << " " << cursor->courseName << " Grade:" << cursor->grade << " Credit Hours:" << cursor->credits << endl;
		PrintListHelper(cursor->next);
	}
}
