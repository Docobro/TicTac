#include <iostream>


class Cells_field{
public:
    char cells[9] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
    void show_ways() {
        std::cout << "������ ����� ����� ����� X, ������ ����� O" << std::endl;
        std::cout << "��� �� ������� � ����� ���� ��������� X ��� O, ������ ����� � ������ �����" << std::endl;
        std::cout << "��������� �����:" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "   |1|2|3|" << std::endl;
        std::cout << "   |4|5|6|" << std::endl;
        std::cout << "   |7|8|9|" << std::endl << std::endl;
    }

    void show_field() {
        std::cout << "������� ����:" << std::endl;
        std::cout << " " << std::endl;
        std::cout << "   |" << cells[0] << "|" << cells[1] << "|" << cells[2] << "|" << std::endl;
        std::cout << "   |" << cells[3] << "|" << cells[4] << "|" << cells[5] << "|" << std::endl;
        std::cout << "   |" << cells[6] << "|" << cells[7] << "|" << cells[8] << "|" << std::endl;
    }

    void clean() {
        for (int i = 0; i<50; ++i){
            std::cout << "/n";
        }
    }

    int get_move() {
        int move;
        std::cin >> move;
        while (move > 9 || move <1 || cells[move-1] != '-'){
            std::cout << std::endl << "������� ����� �� 1 �� 9, �� ����� ��� ������������ �����" << std::endl;
            std::cin >> move;
        }
        return move;
        // ��� ������� ��� ������� �������� �� �������
    }

    int proverka(int x) {
        int y;
        y = x%2 == 0 ? 1 : 2;
        // ��� ������������
        if (cells[0] == cells[1] && cells[1] == cells[2] && cells[0] != '-' && cells[2] != '-'){
            std::cout << "������� " << y << " �����";
            exit(0);
        }
        if (cells[3] == cells[4] && cells[4] == cells[5] && cells[3] != '-' && cells[5] != '-'){
            std::cout << "������� " << y << " �����";
            exit(0);
        }
        if (cells[6] == cells[7] && cells[7] == cells[8] && cells[6] != '-' && cells[8] != '-'){
            std::cout << "������� " << y << " �����";
            exit(0);
        }
        // ��� ����������
        if (cells[0] == cells[3] && cells[3] == cells[6] && cells[0] != '-' && cells[6] != '-'){
            std::cout << "������� " << y << " �����";
            exit(0);
        }
        if (cells[1] == cells[4] && cells[4] == cells[7] && cells[1] != '-' && cells[7] != '-'){
            std::cout << "������� " << y << " �����";
            exit(0);
        }
        if (cells[2] == cells[5] && cells[5] == cells[8] && cells[5] != '-' && cells[8] != '-'){
            std::cout << "������� " << y << " �����";
            exit(0);
        }
        // ��� ����������
        if (cells[0] == cells[4] && cells[4] == cells[8] && cells[0] != '-' && cells[8] != '-'){
            std::cout << "������� " << y << " �����";
            exit(0);
        }
        if (cells[2] == cells[4] && cells[4] == cells[6] && cells[2] != '-' && cells[6] != '-'){
            std::cout << "������� " << y << " �����";
            exit(0);
        }
    }
};



int main() {
    int x = 1;
    setlocale(LC_ALL, "rus");
    Cells_field objCells_field;
    objCells_field.show_ways();
    objCells_field.show_field();
    for (int i = 0; i<9; ++i){
        ++x;
        int move = objCells_field.get_move();
        std::cout << "���: " << move << std::endl;
        if (i%2 == 0){
            objCells_field.cells[move-1] = 'X';
        }
        else objCells_field.cells[move-1] = 'O';
        objCells_field.show_field();
        objCells_field.proverka(x);
    }
}
