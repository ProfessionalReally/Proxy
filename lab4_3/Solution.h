#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

enum Type {emp, easy, medium, hard};

//Абстрактный класс симптома
class AbstractSymptoms
{
protected:
	string NameSymptoms, //Наименование симптома
		ViewSymptoms; //Вид
};

//Интерфейс класса симптом
class Symptoms : public AbstractSymptoms
{
public:
	void PrintName() { cout << "Symptom - " << NameSymptoms << endl; };
	void PrintView() { cout << "View - " << ViewSymptoms << endl; };
	void virtual DetermineSymptoms() = 0;
	void WriteSymptoms(string name, string view) { NameSymptoms = name; ViewSymptoms = view; };
};

//Дочерние классы

//Низкая тяжесть симптома
class EasySymptoms : public Symptoms
{
	void DetermineSymptoms() override { cout << "Determine a easy symptoms" << endl; };
};

//Средняя тяжесть симптома
class MediumSymptoms : public Symptoms
{
	void DetermineSymptoms() override { cout << "Determine a medium symptoms" << endl; };
};

//Высокая тяжесть симптома
class HardSymptoms : public Symptoms
{
	void DetermineSymptoms() override { cout << "Determine a hard symptoms" << endl; };
};


//Абстрактный класс Диагноза
class AbstractDiagnosis
{
protected:
	string NameDiagnosis,
		PeriodDisease;
	Type TypeDiagnosis;
};


//Интерфейс Диагноза
class Diagnosis : public AbstractDiagnosis
{
private:
	Symptoms* symptoms; //Указатель на объект Симптом
public:
	void PrintName() { cout << "Diagnosis - " << NameDiagnosis << endl; };
	void PrintPeriod() { cout << "Period - " << PeriodDisease << endl; };
	void virtual DetermineDiagnosis() = 0;
	void virtual SetTypeDiagnosis() = 0;
	void AddSymptoms(Symptoms* s) { symptoms = s; };
	void WriteDiagnosis(string name, string view) { NameDiagnosis = name; PeriodDisease = view; };
	void PrintSymptoms() { symptoms->PrintName(); };
	void PrintView() { symptoms->PrintView(); };
	Type GetTypeDiagnosis() { return TypeDiagnosis; };
};

//Дочерние классы

//Скрытный период
class HiddenPeriod : public Diagnosis
{
	void SetTypeDiagnosis() override { TypeDiagnosis = easy; };
	void DetermineDiagnosis() override { cout << "Determine a diagnosis hidden period" << endl; };
};

//Инкубационный период
class ProdromalPeriod : public Diagnosis
{
	void SetTypeDiagnosis() override { TypeDiagnosis = medium; };
	void DetermineDiagnosis() override { cout << "Determine a diagnosis prodromal period" << endl; };
};

//Полный период
class FullPeriod : public Diagnosis
{
	void SetTypeDiagnosis() override { TypeDiagnosis = hard; };
	void DetermineDiagnosis() override { cout << "Determine a diagnosis full period" << endl; };
};

class Medication
{
public:
	virtual void FindMedication() = 0;
	virtual void WriteMedication(string s) = 0;
	virtual string GetName() = 0;
	virtual Type GetType() = 0;
};

class RealMedication : public Medication
{
protected:
	string NameMedication;
	Type TypeMedication;
	RealMedication() { TypeMedication = emp; };
};

class ProxyMedication : public Medication
{
private:
	RealMedication* realMed;
	Type TypeDiagnosis;
public:
	ProxyMedication(RealMedication* realMedication) { realMed = realMedication; };
	void SetTypeDiagnosis(Type TD) { TypeDiagnosis = TD; };
	void FindMedication() override
	{
		if (realMed->GetType() == TypeDiagnosis)
			realMed->FindMedication();
		else
			cout << "This treatment is not suitable!" << endl;
	}
	void WriteMedication(string s) override { realMed->WriteMedication(s); };
	Type GetType() override { return realMed->GetType(); };
	string GetName() override{ return realMed->GetName(); };
};

class Prophylaxis : public RealMedication
{
public:
	Prophylaxis() : RealMedication() { TypeMedication = easy; };
	void FindMedication() override { cout << "Easy(Prophylaxis) medication found!" << endl; };
	void WriteMedication(string s) override { NameMedication = s; };
	string GetName() override { return NameMedication; };
	Type GetType() override { return TypeMedication; };
};

class DrugTreatment : public RealMedication
{
public:
	DrugTreatment() : RealMedication() { TypeMedication = medium; };
	void FindMedication() override { cout << "Medium(Drug Treatment) medication found!" << endl; };
	void WriteMedication(string s) override { NameMedication = s; };
	string GetName() override { return NameMedication; };
	Type GetType() override { return TypeMedication; };
};

class GoToHospital : public RealMedication
{
public:
	GoToHospital() : RealMedication() { TypeMedication = hard; };
	void FindMedication() override { cout << "Hard(Go to hospital) medication found!" << endl; };
	void WriteMedication(string s) override { NameMedication = s; };
	string GetName() override { return NameMedication; };
	Type GetType() override { return TypeMedication; };
};


//Пациент
class Patient
{
private:
	string FIO; //ФИО
	Diagnosis* diagnosis; //Указатель на объект диагноз
	ProxyMedication* proxymed;

public:
	Patient(string s) { FIO = s; };
	void PrintName() { cout << "Patient - " << FIO << endl; };
	void PrintDiagnosis() { diagnosis->PrintName(); };
	void PrintPeriod() { diagnosis->PrintPeriod(); };
	void AddDiagnosis(Diagnosis* s) { diagnosis = s; };
	void PrintSymptoms() { diagnosis->PrintSymptoms(); };
	void PrintView() { diagnosis->PrintView(); };
	Type GetTypeDiagnosis() { return diagnosis->GetTypeDiagnosis(); };
	void SetTypeDiagnosis() { proxymed->SetTypeDiagnosis(GetTypeDiagnosis()); };
	void AddMedication(ProxyMedication* s) { proxymed = s; };
	void PrintMedication() { cout << "Medication - " << proxymed->GetName(); };
};