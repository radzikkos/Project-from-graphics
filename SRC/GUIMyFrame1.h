#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"

//// end generated include

#include "Transformation.h"
#include "utility.hpp"
#include <wx/dcbuffer.h>
#include <wx/dcclient.h>
#include <wx/colordlg.h>
#include <vector>

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.
		void m_panelRepaint( wxUpdateUIEvent& event );
		void m_option1OnRadioButton( wxCommandEvent& event );
		void m_option2OnRadioButton( wxCommandEvent& event );
		void m_option3OnRadioButton( wxCommandEvent& event );
		void m_onFunChoice( wxCommandEvent& event );
		void m_paramCtrl1OnText( wxCommandEvent& event );
		void m_paramCtrl2OnText( wxCommandEvent& event );
		void m_paramCtrl3OnText( wxCommandEvent& event );
		void m_paramCtrl4OnText( wxCommandEvent& event );
		void m_paramCtrl5OnText( wxCommandEvent& event );
		void m_paramCtrl6OnText( wxCommandEvent& event );
		void m_paramCtrl7OnText( wxCommandEvent& event );
		void m_saveButtonOnButtonClick( wxCommandEvent& event );
		void m_rotateSlider1OnScroll( wxScrollEvent& event );
		void m_rotateSlider2OnScroll( wxScrollEvent& event );
		void m_rotateSlider3OnScroll(wxScrollEvent& event);
		void m_onAxesReset( wxCommandEvent& event );

		// Funkcja zwracajaca macierz obrotu (obrot nie jest liczony od 0 stopni, ale od ostatniego zapisanego stanu;
		// pozwala to na obrot calego wykresu wokol jego osi wspolrzednych (zamiast wokol osi ekranu)
		Matrix GetRotationMatrix(double, double, double);

		// Funkcja sluzaca do aktualizacji obrazu wyswietlanego na panelu
		void Repaint();
		
		// Funkcja sluzaca do rysowania osi wspolrzednych (razem ze "strzalkami" i podzialkami)
		void DrawAxes(wxBufferedDC&, const Matrix&, const Matrix&);

		// Funkcja sluzaca do rysowania punktow znajdujacych sie w przekazanej tablicy
		void DrawPoints(wxBufferedDC&, const Matrix&, const Matrix&);

		// Funkcja resetujaca polozenia suwakow oraz wszystkie inne powiazane z tym ustawienia; obecnosc takiej funkcji 
		// jest niezbedna ze wzgledu na wykonywanie rotacji wokol osi ukladu wspolrzednych, zamiast wokol osi ekranu;
		// zwykle "przesuniecie" wszystkich suwakow do wartosci 0 nie zawsze daje poczatkowe polozenie wykresu, licza sie
		// tez stany posrednie (troche jak w kostce Rubika)
		void Reset();

		// Funkcja zwracajaca numer aktualnie wybranej funkcji (1-3)
		int funNr() const;

		// Funkcja przydzielajaca poszczegolnym punktom odpowiednie wspolrzedne i kolor
		void getPoints();

		// Wzor funkcji nr 1
		double F1(double, double, double) const;
		// Wzor funkcji nr 2
		double F2(double, double, double) const;
		// Wzor funkcji nr 3
		double F3(double, double, double) const;

		// Wektor punktow (+ kolor)
		std::vector<std::pair<Vector, wxColour>> points;
		// Osie wspolrzednych
		std::vector<Vector> m_axes;
		// "Strzalki" przy osiach
		std::vector<Vector> m_arrowheads;
		// Podzialki na osiach
		std::vector<Vector> m_segments;
		// Historia rotacji (pozwala sledzic wszystkie rotacje wykonane od stanu poczatkowego - w danej chwili w tej tablicy zapisane sa
		// takie wartosci, ktore pozwalaja obrocic wektor/punkt znajdujacy sie w polozeniu poczatkowym do aktualnego polozenia calego ukladu)
		Matrix m_rotationHistory{ 1.0f };

		// Zmienne wykorzystywane przy zapisie obrazu na dysku
		wxBitmap picture_bm;
		wxImage save_img;

		// Zmienne przechowujace aktualne pozycje suwakow (w stopniach; 0-360)
		double m_rotX = 0.0f;
		double m_rotY = 0.0f;
		double m_rotZ = 0.0f;

		// Zmienne przechowujace aktualne wartosci poszczegolnych parametrow
		int m_phi = 0;
		int m_theta = 0;
		double m_r = 0.0f;
		double m_const = 0.0f;
		double m_epsilon = 0.0f;
		double m_delta_r = 0.0f;
		double m_r_max = 0.0f;

		// Numer aktualnie wybranego sposobu rysowania (1-3)
		int m_chartChoice = 0;

		// Zmienne logiczne sluzace do obslugi zmiany stanow poszczegolnych kontrolek
		bool m_chartChanged = false;
		bool m_funChanged = false;
		bool m_resetAxes = false;
		bool m_rChanged = false;
		bool m_phiChanged = false;
		bool m_thetaChanged = false;
		bool m_constChanged = false;
		bool m_epsilonChanged = false;
		bool m_delta_rChanged = false;
		bool m_r_maxChanged = false;

	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
	//// end generated class members
};

#endif // __GUIMyFrame1__
