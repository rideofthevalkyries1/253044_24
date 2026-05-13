// КУРСОВА РАБОТА 253044
#include <iostream>
#include <string>

using namespace std;

class Toy {
protected:
    string Ime;
    int GodinaNaProizvodstvo;

public:
   
    Toy() : Ime("Unknown"), GodinaNaProizvodstvo(2024) {}

   
    Toy(string Ime, int Godina = 2024) : Ime(Ime), GodinaNaProizvodstvo(Godina) {}

    virtual ~Toy() {}

    virtual void Godishnina() const = 0;
    virtual void printInfo() const = 0;
    virtual void provejdaneObuchenie() = 0;


    virtual void Oformlenie() { cout << endl; }
    virtual void Redove() {}

    virtual void infoPilot() {}
};


class EducationalToy : public Toy {
protected:
    string Predmet;
    int Ucheniq;

public:
    EducationalToy() : Toy(), Predmet("General"), Ucheniq(0) {}

    EducationalToy(string Ime, int Godina, string Predmet, int Ucheniq = 1)
        : Toy(Ime, Godina), Predmet(Predmet), Ucheniq(Ucheniq) {
    }

  
    void uvelichiUcheniq() { Ucheniq++; }
    void smeniPredmet(string nov) { Predmet = nov; }

    void Godishnina() const override {
        cout << Ime << " // " << (2026 - GodinaNaProizvodstvo) << " godini v Ruskata armiq" << endl;
    }
};


class MiG15 : public EducationalToy {
private:
    string vid;
    int skorost;
    string dopulnitelenTekst;

public:
    MiG15() : EducationalToy(), vid("Model"), skorost(0), dopulnitelenTekst("") {}

    MiG15(string Ime, int Godina, string Predmet, int Ucheniq, string vid, int skorost = 1075, string tekst = "")
        : EducationalToy(Ime, Godina, Predmet, Ucheniq), vid(vid), skorost(skorost), dopulnitelenTekst(tekst) {
    }

    
    void forsirajDvigatel() { cout << "Dvigateli forsirani!\n"; }
    void proveriSistemi() { cout << "Vsichki sistemi na " << vid << " sa v izpravnost.\n"; }

    void printInfo() const override {
        cout << Ime << ", Predmet: " << Predmet << ", Ucheniq: " << Ucheniq << endl;
        cout << "Vid voenna tehnika: " << vid << ", Maksimalna skorost: " << skorost << " km/h" << endl;
    }

    void provejdaneObuchenie() override {
        cout << dopulnitelenTekst << endl;
    }
};


class EntertainmentToy : public Toy {
protected:
    string tematika;

public:
    EntertainmentToy() : Toy(), tematika("Obshti") {}

    EntertainmentToy(string Ime, int Godina, string tematika = "Kosmos")
        : Toy(Ime, Godina), tematika(tematika) {
    }

    
    void smeniTematika(string nova) { tematika = nova; }
    void proveriPodhod() { cout << "Podhodqshto za izlojba.\n"; }

    void Godishnina() const override {
        cout << Ime << " // " << (2026 - GodinaNaProizvodstvo) << " godini slujba v Ruskata armiq" << endl;
    }
};


class ActionFigure : public EntertainmentToy {
protected:
    string ImeGeroi;
    string Postijenie;
    string finalenTekst;

public:
    ActionFigure() : EntertainmentToy(), ImeGeroi("Voinik"), Postijenie("Nqma"), finalenTekst("") {}

    ActionFigure(string Ime, int Godina, string tematika, string Geroi, string Postijenie, string fTekst = "Geroqt e gotov.")
        : EntertainmentToy(Ime, Godina, tematika), ImeGeroi(Geroi), Postijenie(Postijenie), finalenTekst(fTekst) {
    }

    // 2.d: Собствени методи
    void salutirai() { cout << ImeGeroi << " salutira!\n"; }
    void poziraj() { cout << "Figurata zaema poza.\n"; }

    void printInfo() const override {
        cout << Ime << ", Tematika: " << tematika << endl;
        cout << "Geroi: " << ImeGeroi << ", Postijenie: " << Postijenie << endl;
    }

    void provejdaneObuchenie() override {
        cout << finalenTekst << endl;
    }
};


class YuriGagarin : public ActionFigure {
protected:
    string VoennoZvanie;
    int RojdenaGodina;

public:
    YuriGagarin() : ActionFigure(), VoennoZvanie("Polkovnik"), RojdenaGodina(1900) {}

    YuriGagarin(string Ime, int Godina, string tematika, string Geroi, string Postijenie, string vZvanie, int Rojdena = 1934, string fTekst = "")
        : ActionFigure(Ime, Godina, tematika, Geroi, Postijenie, fTekst), VoennoZvanie(vZvanie), RojdenaGodina(Rojdena) {
    }

   
    void raportuvai() { cout << "Raport: Vsichko e nared!\n"; }
    void pokajiZvanie() { cout << "Zvanie: " << VoennoZvanie << endl; }

    void printInfo() const override {
        cout << Ime << ", Tematika: " << tematika << endl;
        cout << "Geroi: " << ImeGeroi << ", Postijenie: " << Postijenie << endl;
        cout << "Voenno zvanie: " << VoennoZvanie << ", Rojdena godina: " << RojdenaGodina << endl;
    }
};


class Vostok1 : public YuriGagarin {
private:
    string data_subitie;
    string opisanieMisiq;

public:
    Vostok1() : YuriGagarin(), data_subitie("12.04"), opisanieMisiq("Misiq") {}

    Vostok1(string Ime, int Godina, string tematika, string Geroi, string vZvanie, int Rojdena, string data, string opisanie = "Pravime istoriq.")
        : YuriGagarin(Ime, Godina, tematika, Geroi, "purviqt chovek v Kosmosa.", vZvanie, Rojdena, ""),
        data_subitie(data), opisanieMisiq(opisanie) {
    }

    
    void poekhaali() { cout << "Poekhaali!\n"; }
    void orbitalnaInformaciq() { cout << "Orbitalen polet na Vostok 1.\n"; }

    void printInfo() const override {
        cout << "Raketa: " << Ime << endl;
    }

    void Godishnina() const override {}

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
    Toy* toys[] = {
        new MiG15("MiG-15", 1950, "PVO", 10, "Iztrebitel", 1075, "MiG-15 e prochutiqt ruski iztrebitel, chiito pilot e kosmonavtut Yurii Gagarin."),
        new ActionFigure("Kosmonavt", 1934, "Aviaciq SSSR", "Yurii Gagarin", "Purviqt chovek v otkritiq Kosmos", "Ruskata kosmonavtika i aviaciq ostavqt svoqta sleda v istoriqta."),
        new YuriGagarin("Yurii Gagarin", 1934, "Istoriq SSSR", "Yurii Gagarin", "Purvoprohodec", "Polkovnik", 1934, ""),
        new Vostok1("Vostok 1", 1934, "SSSR Kosmicheska misiq", "Yurii Gagarin", "Polkovnik", 1934, "12 april 1961", "Misiqta zavurshva blagopoluchno, tova dokazva tehnicheskiq napreduk na chovechestvoto.")
    };

    for (int i = 0; i < 4; ++i) {
        if (i < 3) cout << (i + 1) << ")" << endl;
        toys[i]->printInfo();
        toys[i]->Godishnina();
        toys[i]->infoPilot();

        
        toys[i]->Oformlenie();
        toys[i]->Redove();

        if (i == 3) cout << endl;
        toys[i]->provejdaneObuchenie();
        cout << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete toys[i];
    }

    return 0;
}