/* This is in some timeTest.cpp  */
int main() {

  // This object is on the stack
  // We initialise it with the Time(int,int,int) constructor (calling the constructor)
  Time t1(12, 0, 5);

  Time t2(1,2,3); //if i don't put brackets, it will call the default one (initialize it with the default one)

  t1.add(t2);
  //once you've added them together, print out t1 and check that t2 has been added to it

  //need to define how to output a time object via overloading
  cout << t1 << endl;
  
  
  cout << t1.getHour() << endl;
  cout << t1.getMins() << endl;
  cout << t1.getSecs() << endl;

}
