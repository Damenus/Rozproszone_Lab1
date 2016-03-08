#include <iostream>
#include <string.h>
#include <stdio.h>
#include <malloc.h>

using namespace std;

struct element
{
	struct element *previous;
	int number;
	struct element *next;
} *begin1, *end1;

struct element *insert1(int obj, struct element *ptr = begin1)
{
	struct element *p;

	if (begin1 == NULL) {
		p = (struct element *)malloc(sizeof(struct element));
		/* zainicjuj sk³adowe nowego elementu */
		p->number = obj;
		p->next = NULL;
		p->previous = NULL;
		begin1 = p;
		end1 = p;
	}
	else {
		p = ptr->next; /* weŸ adres analizowanego elementu */
		if (p != NULL) /* czy koniec listy */
		{
			if (obj > (p->number))
				p->next = insert1(obj, p);
			else
			{
				/* utwórz nowy element */
				p->previous = (struct element *)
					malloc(sizeof(struct element));
				/* zapamiêtaj adres nowego elementu */
				p = p->previous;
				/* zainicjuj sk³adowe nowego elementu */
				p->number = obj;
				p->next = ptr->next;
				p->previous = ptr;

				p->next->previous = p;
				p->previous->next = p;

				if (p->previous = NULL)
					begin1 = p;

			}
		}
		else /* koniec listy */
		{ /* utwórz nowy element */
			p = (struct element *)malloc(sizeof(struct element));
			/* zainicjuj sk³adowe nowego elementu */
			p->number = obj;
			p->next = NULL;
			p->previous = ptr;
			p->previous->next = p; // modifikacja na nastepnym
			end1 = p;
		}
	}
	return p; /* zwróæ adres nowego elementu */
}
int main() {

	int liczba, tryb;

	do {
		cout << "Podaj: 1 insert, 2 na delete, 3 na print_asc, 4 na print_desc, 5 na wyjdz " << endl;
		cin >> tryb;
		if (tryb == 1) {
			cout << "WprowadŸ liczbe: ";
			cin >> liczba;

			insert1(liczba);

			cout << "Dodano!" << endl;
		}
		else if (tryb == 2) {
			cout << "WprowadŸ liczbe: ";
			cin >> liczba;
			//delete1(liczba);
			cout << "Usunieto!" << endl;
		}
		else if (tryb == 3) {
			element *p = begin1;			while (p->next != NULL) {				printf("%d\n", p->number);				p = p->next;			}
			cout << "Koniec!" << endl;
		}
		else if (tryb == 4) {
			element *p = end1;			do {				printf("%d\n", p->number);				p = p->previous;			} while (p->previous != NULL);
			cout << "Koniec!" << endl;
		}
	} while (tryb != 5);

	return 0;
}

