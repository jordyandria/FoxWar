#include <stdexcept>
#include <array>
#include <vector>

using namespace std;

const int MAXCARD = 400;

class Ensemble{
    public:
    //* Constructeur par d�faut
    //* @param[out] e : le ensemble vide
    Ensemble ();
    int getCard() const;
    array<int, MAXCARD> get_T();
    bool estVide() const;
	int cardinal() const;
	void ajoute(int obj);

    private:
    array<int, MAXCARD> t;
    int card;
};
