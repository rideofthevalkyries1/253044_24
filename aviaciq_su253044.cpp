// КУРСОВА РАБОТА 253044

#include <iostream>
#include <string>

using namespace std;

// Изискване: Дефиниране на абстрактен базов клас
class Toy {
protected:
    // Изискване: Използване на спецификатор за достъп protected
    string Ime;
    int GodinaNaProizvodstvo;

public:
    // Изискване: Инициализиране на данните чрез конструктори с параметри
    Toy(string Ime, int Godina) : Ime(Ime), GodinaNaProizvodstvo(Godina) {}

    // Изискване: Осигуряване на виртуален деструктор в базовия клас
    virtual ~Toy() {}

    // Изискване: Деклариране на чисто виртуални функции
    virtual void Godishnina() const = 0;
    virtual void printInfo() const = 0;
    virtual void provejdaneObuchenie() = 0;

    // Изискване: Препокриване (Overriding) на виртуални методи (базова дефиниция)
    virtual void infoPilot() {}
};

// Изискване: Реализиране на йерархия от класове с поне три нива на наследяване (Ниво 1)
class EducationalToy : public Toy {
protected:
    string Predmet;
    int Ucheniq;

public:
    EducationalToy(string Ime, int Godina, string Predmet, int Ucheniq)
        : Toy(Ime, Godina), Predmet(Predmet), Ucheniq(Ucheniq) {
    }

    // Изискване: Препокриване (Overriding) на виртуални методи
    void Godishnina() const override {
        cout << Ime << " // " << (2026 - GodinaNaProizvodstvo) << " godini v Ruskata armiq" << endl;
    }
};

// Изискване: Реализиране на йерархия от класове (Ниво 2 - Разклонение 1)
class MiG15 : public EducationalToy {
private:
    string vid;
    int skorost;
    string dopulnitelenTekst;

public:
    MiG15(string Ime, int Godina, string Predmet, int Ucheniq, string vid, int skorost, string tekst)
        : EducationalToy(Ime, Godina, Predmet, Ucheniq), vid(vid), skorost(skorost), dopulnitelenTekst(tekst) {
    }

    void printInfo() const override {
        cout << Ime << ", Predmet: " << Predmet << ", Ucheniq: " << Ucheniq << endl;
        cout << "Vid voenna tehnika: " << vid << ", Maksimalna skorost: " << skorost << " km/h" << endl;
    }

    void provejdaneObuchenie() override {
        cout << dopulnitelenTekst << endl;
    }
};

// Изискване: Реализиране на йерархия от класове (Ниво 1 - Разклонение 2)
class EntertainmentToy : public Toy {
protected:
    string tematika;

public:
    EntertainmentToy(string Ime, int Godina, string tematika)
        : Toy(Ime, Godina), tematika(tematika) {
    }

    void Godishnina() const override {
        cout << Ime << " // " << (2026 - GodinaNaProizvodstvo) << " godini slujba v Ruskata armiq" << endl;
    }
};

// Изискване: Реализиране на йерархия от класове (Ниво 2)
class ActionFigure : public EntertainmentToy {
protected:
    string ImeGeroi;
    string Postijenie;
    string finalenTekst;

public:
    ActionFigure(string Ime, int Godina, string tematika, string Geroi, string Postijenie, string fTekst)
        : EntertainmentToy(Ime, Godina, tematika), ImeGeroi(Geroi), Postijenie(Postijenie), finalenTekst(fTekst) {
    }

    void printInfo() const override {
        cout << Ime << ", Tematika: " << tematika << endl;
        cout << "Geroi: " << ImeGeroi << ", Postijenie: " << Postijenie << endl;
    }

    void provejdaneObuchenie() override {
        cout << finalenTekst << endl;
    }
};

// Изискване: Реализиране на йерархия от класове (Ниво 3)
class YuriGagarin : public ActionFigure {
protected:
    string rang;
    int RojdenaGodina;

public:
    YuriGagarin(string Ime, int Godina, string tematika, string Geroi, string Postijenie, string rang, int Rojdena, string fTekst)
        : ActionFigure(Ime, Godina, tematika, Geroi, Postijenie, fTekst), rang(rang), RojdenaGodina(Rojdena) {
    }

    void printInfo() const override {
        cout << Ime << ", Tematika: " << tematika << endl;
        cout << "Geroi: " << ImeGeroi << ", Postijenie: " << Postijenie << endl;
        cout << "Voenno zvanie: " << rang << ", Rojdena godina: " << RojdenaGodina << endl;
    }
};

// Изискване: Реализиране на йерархия от класове (Ниво 4)
class Vostok1 : public YuriGagarin {
private:
    string data_subitie;
    string opisanieMisiq;

public:
    Vostok1(string Ime, int Godina, string tematika, string Geroi, string rang, int Rojdena, string data, string opisanie)
        : YuriGagarin(Ime, Godina, tematika, Geroi, "purviqt chovek v Kosmosa.", rang, Rojdena, ""),
        data_subitie(data), opisanieMisiq(opisanie) {
    }

    void printInfo() const override {
        cout << "Raketa: " << Ime << endl;
    }

    void Godishnina() const override {
    }

    void provejdaneObuchenie() override {
        cout << "4)" << endl;
        cout << Ime << ", Tematika: " << tematika << endl;
        cout << "Pilot: " << ImeGeroi << ", Data na subitieto: " << data_subitie << endl;
        cout << opisanieMisiq << endl;
    }

    void infoPilot() override {
        cout << ImeGeroi << " e ruski voenen pilot, " << Postijenie << endl;
    }
};

int main() {
    // Изискване: Полиморфична обработка на обекти чрез масив от указатели към базовия клас
    Toy* toys[] = {
        // Изискване: Динамично управление на паметта (създ. с new)
        new MiG15("MiG-15", 1950, "PVO", 10, "Iztrebitel", 1075, "MiG-15 e prochutiqt ruski iztrebitel, chiito pilot e kosmonavtut Yurii Gagarin."),

        new ActionFigure("Kosmonavt", 1934, "Aviaciq SSSR", "Yurii Gagarin", "Purviqt chovek v otkritiq Kosmos", "Ruskata kosmonavtika i aviaciq ostavqt svoqta sleda v istoriqta."),

        new YuriGagarin("Yurii Gagarin", 1934, "Istoriq SSSR", "Yurii Gagarin", "Purvoprohodec", "Polkovnik", 1934, ""),

        new Vostok1("Vostok 1", 1934, "SSSR Kosmicheska misiq", "Yurii Gagarin", "Polkovnik", 1934, "12 april 1961", "Misiqta zavurshva blagopoluchno, tova dokazva tehnicheskiq napreduk na chovechestvoto.")
    };

    // Изискване: Полиморфична обработка чрез обхождане на масива
    for (int i = 0; i < 4; ++i) {
        if (i < 3) cout << (i + 1) << ")" << endl;

        // Изискване: Полиморфично извикване на препокрити виртуални методи
        toys[i]->printInfo();
        toys[i]->Godishnina();
        toys[i]->infoPilot();

        if (i == 3) cout << endl;

        toys[i]->provejdaneObuchenie();
        cout << endl;
    }

    // Изискване: Динамично управление на паметта (освобождаване с delete)
    for (int i = 0; i < 4; ++i) {
        delete toys[i];
    }

    return 0;
}