  int quadrato[n][n] = {{0}}, k = 1;
  int i, j, inew, jnew;
  
  i = 0; j = n/2;
  nn = n * n;
  for ( k = 1; k <= nn; k++ ) {
    quadrato[i][j] = k;
    inew = ( i == 0 ) ? n - 1 : i - 1;
    jnew = ( j == n - 1 ) ? 0 : j + 1;
    if ( quadrato[ inew ][ jnew ] == 0 ) {
      i = inew;
      j = jnew;
    }
    else {
      i++; 
    }
  }
