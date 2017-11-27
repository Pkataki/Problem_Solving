import java.util.*;
import java.math.BigInteger;
public class Main
{
	public static BigInteger a,b,n,m;
	public static BigInteger[][] mult( BigInteger[][] mat, BigInteger[][] mat1)
	{
		
		BigInteger[][] ans = new BigInteger[2][2];
		
		for(int i = 0 ; i < 2 ; i++)
		{
			for(int j = 0 ; j < 2 ; j++)
			{
				ans[i][j] = new BigInteger("0");
				for(int k = 0 ; k < 2 ; k++)
				{
					BigInteger aux = mat[i][k].multiply(mat1[k][j]);
					ans[i][j] = ans[i][j].add(aux);
					ans[i][j] = ans[i][j].mod(m);
				}
			}
		}
		return ans;
	}
	
	public static BigInteger solve(BigInteger[][] t, BigInteger pot)
	{
		BigInteger[][] ans = new BigInteger[2][2];
		ans[0][0] = BigInteger.ONE;
		ans[1][1] = BigInteger.ONE;
		ans[0][1] = BigInteger.ZERO;
		ans[1][0] = BigInteger.ZERO;
		
	
		while(pot.equals(BigInteger.ZERO) == false)
		{
			BigInteger b1 = new BigInteger("2");
			BigInteger b2 = pot.mod(b1);
			if(b2.equals(BigInteger.ONE) == true)
			{
				ans = mult(ans,t);	
			}
			t = mult(t,t);
			pot = pot.shiftRight(1);
		}
		
		BigInteger aux = ans[0][0].multiply(BigInteger.ONE);
		aux = aux.mod(m);
		BigInteger aux1 = aux.add(ans[0][1]);
		return aux1.mod(m);
	}
	
	public static void main(String[] args)
	{
		int test;
		Scanner sc = new Scanner(System.in);
		test = sc.nextInt();
		while(test != 0)
		{
			test--;
			a = sc.nextBigInteger();
			b = sc.nextBigInteger();
			n = sc.nextBigInteger();
			m = sc.nextBigInteger();
			BigInteger[][] t = new BigInteger[2][2];
			t[0][0] = a.mod(m);
			t[0][1] = b.mod(m);
			t[1][1] = BigInteger.ONE;
			t[1][0] = BigInteger.ZERO;
			BigInteger ans = solve(t,n);
			System.out.println(ans);
		}
	}
}
