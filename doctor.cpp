#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter the size of the square matrix: ";
  cin >> n;

  int arr[n][n];
  cout << "Enter the elements of the matrix: \n";
  for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
  cin >> arr[i][j];

  int sum = 0;
  for(int i=0; i<n; i++)
  for(int j=0; j<n; j++)
  if(i==j || i+j==n-1)
  sum += arr[i][j];

  // Subtract the middle element if the size of the matrix is odd
  if(n%2 != 0)
  sum -= arr[n/2][n/2];

  cout << "The sum of the diagonals is: " << sum << endl;

  return 0;
}
