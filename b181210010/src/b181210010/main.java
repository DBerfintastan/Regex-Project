/**
*
* @author Deniz Berfin Tastan deniz.tastan@ogr.sakarya.edu.tr
* @since 19.03.2021
* <p>
* B181210010 1.Ogretim A grubu
* </p>
*/

package b181210010;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class main {
	public static String classBul(String text, String sonrakiKelime) {
		String sonuc = "";
		int kelimeIndex = text.indexOf(sonrakiKelime);
		String tep = text.substring(kelimeIndex);
		if (tep.indexOf(" ") > 0) {
			tep = tep.substring(tep.indexOf(" ") + 1);
			if (tep.indexOf(" ") > 0)
				sonuc = tep.substring(0, tep.indexOf(" "));
			else
				sonuc = tep;
		}
		return sonuc;
	}

	public static void main(String[] args) {
		String str;
		try {
			FileInputStream fStream = new FileInputStream("src/program.cpp");
			DataInputStream dStream = new DataInputStream(fStream);
			BufferedReader oku = new BufferedReader(new InputStreamReader(dStream));
			int x = 0;
			while ((str = oku.readLine()) != null) {
				String[] fonksiyon_isimleri = new String[20];
				int sayac_fonksiyon = 0;
				boolean classAra = str.contains("class");
				if (classAra == true) {
					System.out.println("S�n�f: " + classBul(str, "class"));
				}

				Pattern fonksiyonPattern = Pattern.compile(
						"^\\s*(?:(?:inline|static)\\s+){0,2}(?!else|typedef|return|~)\\w+\\s+\\*?\\s*(\\w+)\\s*\\([^0]*\\)\\s*;?");
				Matcher fonksiyonMatcher = fonksiyonPattern.matcher(str);
				String[] parametreler;
				String[] parametre;
				String[] parametreTurleri;
				String[] donusTurleri;
				while (fonksiyonMatcher.find()) {
					int sayac = 0;
					String a = fonksiyonMatcher.group();
					String[] split = a.split("\\W");
					sayac_fonksiyon++;
					fonksiyon_isimleri[sayac_fonksiyon] = split[1];
					sayac++;
					for (int k = 0; k <= sayac + 1; k++) {

						if (fonksiyon_isimleri[k] != null) {
							System.out.println("       " + fonksiyon_isimleri[k]);
						}
					}
					String satir = a;
					Pattern p = Pattern.compile("(?<=\\()([^\\]]+)(?=\\))");
					Matcher m = p.matcher(satir);
					donusTurleri = satir.split(" ");
					if (m.find() == false) {
						System.out.println("                Parametre:" + 0);
						System.out.println("                D�n�� T�rleri:" + donusTurleri[0]);
					} else {
						parametreler = satir.split("[\\(||\\)]");
						parametre = parametreler[1].split(",");
						parametreTurleri = parametre[0].split(" ");
						System.out.print("                Parametre:"+parametre.length);
						System.out.print("(");
						for(int i=0;i<parametre.length;i++)
						{
							System.out.print(parametre[i]+",");
						}
						System.out.print(")");
						System.out.println(" ");
						System.out.println("                D�n�� T�rleri:" + donusTurleri[0]);
						
					}
					x++;
				}
				
			}dStream.close();
		} catch (

		Exception e) {
			System.err.println("hata:" + e.getMessage());
		}
	}
}