#include <stdio.h>
#include <stdlib.h>
#define GNUPLOT_PATH "C:/gnuplot/bin/gnuplot.exe" // gnuplot.exe�̂���ꏊ
// \�ł͂Ȃ��A/���g���܂��傤�B
// Program Files��PROGRA~1�AProgram Files(x86)��PROGRA~2�ɒu�������܂��傤


int main()
{
	FILE *gp;	// For gnuplot

	// gnuplot�̋N���R�}���h
	if ((gp = _popen(GNUPLOT_PATH, "w")) == NULL) {	// gnuplot���p�C�v�ŋN��
		fprintf(stderr, "�t�@�C����������܂��� %s.", GNUPLOT_PATH);
		exit(EXIT_FAILURE);
	}

	// --- gnuplot�ɃR�}���h�𑗂� --- //
	fprintf(gp, "set xrange [-10:10]\n"); // �͈͂̎w��(�ȗ���)
	fprintf(gp, "set yrange [-1:1]\n");

	fprintf(gp, "plot sin(x)\n"); 	//sin(x)��`��

	fflush(gp); // �o�b�t�@�Ɋi�[����Ă���f�[�^��f���o���i�K�{�j
	system("pause");
	fprintf(gp, "exit\n"); // gnuplot�̏I��
	_pclose(gp);
}
