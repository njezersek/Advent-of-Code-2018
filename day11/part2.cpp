#include <iostream>

int main(){
  int input = 5235;
  int grid[300][300];

  for(int i=0; i<300; i++){
    for(int j=0; j<300; j++){
      int x = i+1;
      int y = j+1;
      int rackID = x+10;
      int power = rackID * y;
      power += input;
      power *= rackID;
      power = (power/100)%10;
      power -= 5;

      grid[i][j] = power;
    }
  }

  int maxPower = -100000;
  int x = 0;
  int y = 0;
  int size = 0;
  for(int s = 1; s<=300; s++){
    std::cout << s << "\n";
    for(int i=0; i<300-s; i++){
      for(int j=0; j<300-s; j++){
        int power = 0;
        for(int ii=0; ii<s; ii++){
          for(int jj=0; jj<s; jj++){
            power+=grid[i+ii][j+jj];
          }
        }
        if(power > maxPower){
          maxPower = power;
          x = i+1;
          y = j+1;
          size = s;
        }
      }
    }
  }

  std::cout << x << "," << y << "," << size << " " << maxPower;
  return 0;
}
