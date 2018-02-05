//HW1  Polynomial Operations using linked lists

//Due 11:59 pm, February 2 (Friday)
//
//A polynomial is implemented using a linked list.  Only non-zero coefficients are included in linked list.
//Implment member functions operator+ , operator* , and add term
//
//You have to use the main function and print_linked_list provided to you.

#include <iostream>

using namespace std;

class term {
public:
	int power;
	int coef;
	term * next;
	term() { next = nullptr; }
	term(int c, int p) { power = p; coef = c; next = nullptr; }
};

class polynomial {
public:
	int num_terms;
	term * head;
	polynomial() { num_terms = 0; head = nullptr; }

	void add_term(int c, int p);
	//If the polynomial does not contain a term with power p, 
	//then add this new term.
	//If the polynomial contains a term with power p,
	//then add c to the existing coef.

	polynomial operator+(polynomial P);
	polynomial operator*(polynomial P);
	void print_polynomial();
};


void polynomial::print_polynomial() {
	cout << endl;
	term * p = head;
	while (p != nullptr) {
		cout << p->coef << " " << p->power << "   ";
		p = p->next;
	}
}
void polynomial::add_term(int c, int p) {
    term *p1 = new term(c,p);
    term *p2 = head;
    term *p3 = head;

    p1->next = nullptr;
    if(head == nullptr){
        head = p1;
        return;
    }
    while(p2 != nullptr){
        if(p2->power == p1->power && p2->coef + p1->coef != 0){
            p2->coef = p2->coef + p1->coef;
            delete p1;
            break;
        }
        if(p1->power > p2->power){
            head = p1;
            p1->next = p2;
            break;
        }
        if(p1->power < p2->power && p2->next == nullptr){
            p2->next = p1;
            break;
        }
        if(p2->next != nullptr){
            if(p1->power < p2->power && p1->power > p2->next->power){
                p1->next = p2->next;
                p2->next = p1;
                break;
            }
        }
        if(p2->coef + p1->coef == 0 && p2->power == p1->power){
            p3 = p2->next;
            delete p1;
            delete p2;
            p2 = head;
            p2->next = p3;
            break;
        }
        //cout << p2->coef << " " << p2->power << endl;
        p2 = p2->next;
    }
    //cout << p2->coef << " " << p2->power << endl;
}

	


polynomial polynomial::operator+(polynomial P) {
    polynomial temp;//new linked_list to store the result;
    term *p1,*p2;
    p1 = head;
    p2 = P.head;
    while(p1 != nullptr){
        temp.add_term(p1->coef,p1->power);
        p1 = p1->next;
    }
    while(p2 != nullptr){
        temp.add_term(p2->coef,p2->power);
        p2 = p2->next;
    }
    return temp;
}
	
polynomial polynomial::operator*(polynomial P) {
    polynomial temp;
    term *p1,*p2;
    p1 = head;
    p2 = P.head;
    int sum_coef = 0,sum_power = 0;
    while(p2 != nullptr){
        while(p1 != nullptr){
            sum_coef = p1->coef * p2->coef;
            //cout << endl;
            //cout << sum_coef << endl;
            sum_power = p1->power + p2->power;
            temp.add_term(sum_coef,sum_power);
            p1 = p1->next;
        }
        p2 = p2->next;
        p1 = head;
    }
    return temp;
}


int main() {
	polynomial p1, p2, p3, p4, p5, p6;
	int num_t;
	cout << "Enter numer of terms" << endl;
	cin >> num_t;
	cout << "Enter all terms" << endl;
	for (int i = 0; i < num_t; i++) { //You don't need to check for input error
		int c, p;
		cin >> c >> p;
		p1.add_term(c, p);
	}
	p1.print_polynomial();
	cout << endl;
	cout << "Enter numer of terms" << endl;
	cin >> num_t;
	cout << "Enter all terms" << endl;
	for (int i = 0; i < num_t; i++) { //You don't need to check for input error
		int c, p;
		cin >> c >> p;
		p2.add_term(c, p);
	}
	p2.print_polynomial();
	p3 = p1 + p2;
	p3.print_polynomial();
    p4 = p1 * p2;
    p4.print_polynomial();
	
	getchar();
	getchar();
	return 0;
}
