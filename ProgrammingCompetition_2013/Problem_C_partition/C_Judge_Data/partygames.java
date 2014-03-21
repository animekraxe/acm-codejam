
import java.io.*;
import java.util.*;
import java.awt.geom.*;

/**
 * Solution to Party Games
 * 
 * @author vanb
 */
public class partygames
{
    public Scanner sc;
    public PrintStream ps;
        
    /**
     * Driver.
     * @throws Exception
     */
    public void doit(String file) throws Exception
    {
        sc = new Scanner( new File( file ) );
        ps = System.out; //new PrintStream( new FileOutputStream( "partygames.out" ) ); 
                        
        for(;;)
        {
            int n = sc.nextInt();
            if( n==0 ) break;
            
            // Read the names, convert to all upper case
            String names[] = new String[n];
            for( int i=0; i<n; i++ )
            {
                names[i] = sc.next().toUpperCase();
            }
            
            // Sort
            Arrays.sort( names );
            
            // Find the two in the middle, call them a and b 
            String a = names[n/2-1];
            String b = names[n/2];
            
            // The string we want is all the characters of a, up until a<>b, 
            // or we hit the end of a.
            String result = ""; 
            
            // c will be a substring of a that we'll base the result on
            String c = "";
            
            // Go from the shortest possible string to the largest,
            // looking for one that works.
            for( int i=0; i<a.length(); ++i ) 
            {
                // Get the next character of a
                char ch = a.charAt( i );
                
                // In order for the result to be >=a, then the last
                // letter must be one more than the corresponding letter
                // of a. There are two exceptions: If this letter is Z, then
                // there is no next letter. And, if it's the last letter of a,
                // then we can just use a as the result and we don't need to increment it.
                if( ch!='Z' && i<a.length()-1 ) ++ch;
                result = c+ch;
                
                // If this string works, Hooray! Get out of the loop.
                if( result.compareTo( a ) >= 0 && result.compareTo( b ) < 0 ) break;

                // Otherwise, move on to the next.
                c += a.charAt(i);
            }
            
            ps.println( result );
        }
    }
    
    /**
     * @param args
     */
    public static void main( String[] args ) throws Exception
    {
        new partygames().doit(args[0]);
        
//        Random random = new Random();
//        
//        char alphabet[] = "QWERTYUIOPASDFGHJKLZXCVBNM".toCharArray();
//        System.out.println( 1000 );
//        HashSet<String> seen = new HashSet<String>();
//        for( int i=0; i<1000; i++ ) 
//        {
//            String name = "";
//            do
//            {
//                int k = random.nextInt(30)+1;
//                name = "";
//                for( int j=0; j<k; j++ )
//                {
//                    name += alphabet[random.nextInt(26)];
//                }
//            } while( seen.contains( name ));
//            seen.add( name );
//            System.out.println( name );
//        }
    }

}
