unsigned long long sum = 1;

unsigned long long silniaReku(int num) {
  sum *= num;
  if (num > 2) silniaReku(--num);
  return sum;
}