#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100

typedef struct {
    int systolic;
    int diastolic;
} BloodPressure;

typedef struct {
    int day, month, year;
} VisitDate;

typedef struct {
    char name[50];
    int age;
    char phone[16];
    BloodPressure bp;
    VisitDate visit;
} Patient;

void addPatient(Patient *p, const char *name, int age, const char *phone,
                int systolic, int diastolic, VisitDate date) {
    if (p == NULL) return;

    snprintf(p->name, sizeof p->name, "%s", name);
    p->age = age;
    snprintf(p->phone, sizeof p->phone, "%s", phone);
    p->bp.systolic = systolic;
    p->bp.diastolic = diastolic;
    p->visit = date;
}

int main(void) {
    Patient patients[MAX_PATIENTS] = {0};
    VisitDate today = {19, 11, 2026};

    addPatient(&patients[0], "Anu", 35, "9876543210", 120, 80, today);

    printf("Patient: %s\n", patients[0].name);
    printf("Age: %d\n", patients[0].age);
    printf("Phone: %s\n", patients[0].phone);
    printf("Blood pressure: %d/%d\n",
           patients[0].bp.systolic, patients[0].bp.diastolic);
    printf("Visit date: %02d/%02d/%04d\n",
           patients[0].visit.day, patients[0].visit.month,
           patients[0].visit.year);
    return 0;
}
