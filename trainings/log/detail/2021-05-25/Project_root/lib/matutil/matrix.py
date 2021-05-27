# Ex. 2 Class Matrix
 
import csv


class EugenieError(Exception):
    pass


class Matrix:
    
    def __init__(self,csv_a):
        self.M = []
        if type(csv_a) is str:
            with open(csv_a) as matrix_file:
                self._fill_matrix(matrix_file)
        else:
            self._fill_matrix(csv_a)
    
    def extract(self,R):
        m_R = []
        for F_Nr in self.M:
            if F_Nr [0] == R:
                try:
                    m_R.append([float(e) for e in F_Nr[1:]])
                except ValueError:
                    raise EugenieError()
        return(m_R)    

    def _fill_matrix(self, filelike):
        matrix = csv.reader(filelike, delimiter=';')
        for F_Nr in matrix:
            if F_Nr[0] == 'Language':
                for i in range(2, len(F_Nr)):
                    if F_Nr[i] != 'RUS' and F_Nr[i] !='UA':
                        F_Nr[i]= 'both'
           
            self.M.append(F_Nr)
