class Solution {
  int tlen, slen;

public:
  vector<int> movesToStamp( const string& stamp, 
                            string target ) {
    vector<int> rmoves;
    tlen = target.length();
    slen = stamp.length();
    const string aim( tlen, '*' );

    while ( target != aim ) {
      int stamppos = remove( target, stamp );
      if ( stamppos == tlen ) {
        return {};
      }
      rmoves.push_back( stamppos );
    }

    vector<int> moves( rmoves.rbegin(), rmoves.rend() );
    return moves;
  }

  int remove( string& target, const string& stamp ) {
    for ( int iter = 0; iter < tlen; ++iter ) {
      bool bmatchany = false;
      int  jter      = 0;
      for ( ; jter < slen && iter + jter < tlen; jter++ ) {
        if ( target[ iter + jter ] == stamp[ jter ] ) {
          bmatchany = true;
        } else if ( target[ iter + jter ] != '*' ) {
          break;
        }
      }

      if ( jter == slen && bmatchany ) {
        // iterated thru the whole stamp && matched at least one character
        const auto it = target.begin() + iter;
        std::fill( it, it + slen, '*' );
        return iter;
      }
    }
    return tlen;
  }
};