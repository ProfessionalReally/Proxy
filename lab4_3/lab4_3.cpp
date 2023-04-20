#include "Solution.h"

int main()
{
	//Создание разных видов симптомов
	Symptoms* symptoms1 = new EasySymptoms(),
		* symptoms2 = new MediumSymptoms(),
		* symptoms3 = new HardSymptoms();

	//Создание разных видов диагнозов
	Diagnosis* diagnosis1 = new HiddenPeriod(),
		* diagnosis2 = new ProdromalPeriod(),
		* diagnosis3 = new FullPeriod();

	//Создание различных пациентов
	Patient* pt1 = new Patient("Ivan Ivanovich Ivanov"),
		* pt2 = new Patient("Ruslan Ahmedovich Uranov"),
		* pt3 = new Patient("Irina Pavlova Fedorova");

	//Создаем различные реальные лечения
	RealMedication* prophylaxis = new Prophylaxis(),
		* drugtreatment = new DrugTreatment(),
		* gotohospital = new GoToHospital();

	//Создаем различные тестеры
	ProxyMedication* ProxyTestProphylaxis = new ProxyMedication(prophylaxis),
		* ProxyTestDrugTreatment = new ProxyMedication(drugtreatment),
		* ProxyTestGoToHospital = new ProxyMedication(gotohospital);


	cout << "===================================================" << endl;
	cout << "Easy Symptoms and Hidden Period: " << endl;

	//Записать симптом
	symptoms1->WriteSymptoms("Headache", "Easy Symptoms");

	//Определить вид симптома
	symptoms1->DetermineSymptoms();

	//Добавить симптомы к диагнозу
	diagnosis1->AddSymptoms(symptoms1);

	//Записать диагноз
	diagnosis1->WriteDiagnosis("Overwork", "Hidden Period");

	//Определить вид диагноза
	diagnosis1->DetermineDiagnosis();


	//Установить тип диагноза
	diagnosis1->SetTypeDiagnosis();

	//Поставить диагноз пациенту
	pt1->AddDiagnosis(diagnosis1);
	
	cout << endl; cout << endl; cout << endl;
	//НЕПРАВИЛЬНОЕ ЛЕЧЕНИЕ

	//Получить лечение
	pt1->AddMedication(ProxyTestDrugTreatment);

	//Установить тип диагноза в лечении
	pt1->SetTypeDiagnosis();

	//Поиск лечения
	ProxyTestDrugTreatment->FindMedication();

	//Выписать лечение
	ProxyTestDrugTreatment->WriteMedication("Pills");

	pt1->PrintMedication();

	cout << endl; cout << endl; cout << endl;
	//ПРАВИЛЬНОЕ ЛЕЧЕНИЕ

	//Получить лечение
	pt1->AddMedication(ProxyTestProphylaxis);

	//Установить тип диагноза в лечении
	pt1->SetTypeDiagnosis();

	//Поиск лечения
	ProxyTestProphylaxis->FindMedication();

	//Выписать лечение
	ProxyTestProphylaxis->WriteMedication("Chill");

	pt1->PrintMedication();

	cout << endl; cout << endl; cout << endl;

	//Вывод конечной информации
	pt1->PrintName();
	pt1->PrintSymptoms();
	pt1->PrintView();
	pt1->PrintDiagnosis();
	pt1->PrintPeriod();
	
	
	cout << endl; cout << endl; cout << endl;

	cout << "===================================================" << endl;
	cout << "Medium Symptoms and Prodromal Period: " << endl;

	//Записать симптом
	symptoms2->WriteSymptoms("Cough", "Medium Symptoms");

	//Определить вид симптома
	symptoms2->DetermineSymptoms();

	//Добавить симптомы к диагнозу
	diagnosis2->AddSymptoms(symptoms2);

	//Записать диагноз
	diagnosis2->WriteDiagnosis("Bronchitis", "Prodromal Period");

	//Определить вид диагноза
	diagnosis2->DetermineDiagnosis();

	//Установить тип диагноза
	diagnosis2->SetTypeDiagnosis();

	//Поставить диагноз пациенту
	pt2->AddDiagnosis(diagnosis2);

	cout << endl; cout << endl; cout << endl;

	//НЕПРАВИЛЬНОЕ ЛЕЧЕНИЕ

	//Получить лечение
	pt2->AddMedication(ProxyTestProphylaxis);

	//Установить тип диагноза в лечении
	pt2->SetTypeDiagnosis();

	//Поиск лечения
	ProxyTestProphylaxis->FindMedication();

	//Выписать лечение
	ProxyTestProphylaxis->WriteMedication("Chill");

	pt2->PrintMedication();

	cout << endl; cout << endl; cout << endl;

	//ПРАВИЛЬНОЕ ЛЕЧЕНИЕ

	//Получить лечение
	pt2->AddMedication(ProxyTestDrugTreatment);

	//Установить тип диагноза в лечении
	pt2->SetTypeDiagnosis();

	//Поиск лечения
	ProxyTestDrugTreatment->FindMedication();

	//Выписать лечение
	ProxyTestDrugTreatment->WriteMedication("Pills");

	pt2->PrintMedication();

	cout << endl; cout << endl; cout << endl;

	//Вывод конечной информации
	pt2->PrintName();
	pt2->PrintSymptoms();
	pt2->PrintView();
	pt2->PrintDiagnosis();
	pt2->PrintPeriod();
	


	cout << endl; cout << endl; cout << endl;

	cout << "===================================================" << endl;
	cout << "Hard Symptoms and Full Period: " << endl;
	
	//Записать симптом
	symptoms3->WriteSymptoms("Temperature", "Hard Symptoms");

	//Определить вид симптома
	symptoms3->DetermineSymptoms();

	//Добавить симптомы к диагнозу
	diagnosis3->AddSymptoms(symptoms3);

	//Записать диагноз
	diagnosis3->WriteDiagnosis("Coronavirus", "Full Period");

	//Определить вид диагноза
	diagnosis3->DetermineDiagnosis();

	//Установить тип диагноза
	diagnosis3->SetTypeDiagnosis();

	//Поставить диагноз пациенту
	pt3->AddDiagnosis(diagnosis3);

	cout << endl; cout << endl; cout << endl;
	
	//НЕПРАВИЛЬНОЕ ЛЕЧЕНИЕ

	pt3->AddMedication(ProxyTestProphylaxis);

	//Установить тип диагноза в лечении
	pt3->SetTypeDiagnosis();

	//Поиск лечения
	ProxyTestProphylaxis->FindMedication();

	//Выписать лечение
	ProxyTestProphylaxis->WriteMedication("Vitamins");

	pt3->PrintMedication();
	
	cout << endl; cout << endl; cout << endl;
	//ПРАВИЛЬНОЕ ЛЕЧЕНИЕ
	
	//Получить лечение
	pt3->AddMedication(ProxyTestGoToHospital);

	//Установить тип диагноза в лечении
	pt3->SetTypeDiagnosis();

	//Поиск лечения
	ProxyTestGoToHospital->FindMedication();

	//Выписать лечение
	ProxyTestGoToHospital->WriteMedication("Go to Hospital");

	pt3->PrintMedication();
	cout << endl; cout << endl; cout << endl;
	
	//Вывод конечной информации
	pt3->PrintName();
	pt3->PrintSymptoms();
	pt3->PrintView();
	pt3->PrintDiagnosis();
	pt3->PrintPeriod();
	
	cout << endl; cout << endl; cout << endl;

	//Удаление объектов
	delete pt1,
		pt2,
		pt3;

	delete symptoms1,
		symptoms2,
		symptoms3;

	delete diagnosis1,
		diagnosis2,
		diagnosis3;

	delete prophylaxis,
		drugtreatment,
		gotohospital;
	
	delete ProxyTestProphylaxis,
		ProxyTestDrugTreatment,
		ProxyTestGoToHospital;
}
