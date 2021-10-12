const guessNumber = (right, left = 1) => {
  const mid = ((left + right) / 2) << 0;
  switch(guess(mid)) {
    case 0:
      return mid;
    case -1:
      return guessNumber(mid - 1, left);
    case 1:
      return guessNumber(right, mid + 1);
  }
};