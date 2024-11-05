import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.zip.GZIPOutputStream;
import java.util.zip.GZIPInputStream;
import java.io.BufferedReader;
import java.io.InputStream;

public class CesarCipher {

    public static void InputCesarCipher() throws IOException {
        FileOutputStream fos = new FileOutputStream("Tekst.txt");
        fos.write(("Lubię, kiedy kobieta... " +
                "Lubię, kiedy kobieta omdlewa w objęciu, " +
                "Kiedy w lubieżnym zwisa przez ramię przegięciu, " +
                "Gdy jej oczy zachodzą mgłą, twarz cała blednie, " +
                "I wargi się wilgotne rozchylą bezwiednie. " +
                "Lubię, kiedy ją rozkosz i żądza oniemi, " +
                "Gdy wpija się w ramiona palcami drżącemi, " +
                "Gdy krótkim, urywanym oddycha oddechem, " +
                "I oddaje się cała z mdlejącym uśmiechem.  " +
                "I lubię ten wstyd, co się kobiecie zabrania " +
                "Przyznać, że czuje rozkosz, że moc pożądania " +
                "Zwalcza ją, a sycenie żądzy oszalenia, " +
                "Gdy szuka ust, a lęka się słów i spojrzenia.  " +
                "Lubię to — i tę chwilę lubię, gdy koło mnie " +
                "Wyczerpana, zmęczona leży nieprzytomnie, " +
                "A myśl moja już od niej wybiega skrzydlata " +
                "W nieskończone przestrzenie nieziemskiego świata.").getBytes());
        fos.close();

    }

    public static String cipher(String msg, int shift){
        String s = "";
        int len = msg.length();

        for(int x = 0; x < len; x++){
            char c = (char)(msg.charAt(x) + shift);
            if ((msg.charAt(x)) == ' ' ){
                s += ' ';
                continue;
            }
            if ((msg.charAt(x)) == ',' ){
                s += ',';
                continue;
            }
            if ((msg.charAt(x)) == '.' ){
                s += '.';
                continue;
            }
            if (c > 'z')
                s += (char)(msg.charAt(x) - (26-shift));
            else
                s += (char)(msg.charAt(x) + shift);
        }
        return s;
    }

    public static void OutputCesarCipher() throws IOException {
        String encoding = "";

        InputStream inputStream = new FileInputStream("Tekst.txt");
        //creating an InputStreamReader object
        InputStreamReader isReader = new InputStreamReader(inputStream);
        //Creating a BufferedReader object
        BufferedReader reader = new BufferedReader(isReader);
        StringBuffer sb = new StringBuffer();
        String str;
        while((str = reader.readLine())!= null){
            sb.append(str);
        }
        encoding = (sb.toString());
        cipher(encoding,3);

        FileOutputStream fos = new FileOutputStream("Szyfr.txt");
        fos.write((cipher(encoding,3)).getBytes());
        fos.close();
        FileInputStream fis = new FileInputStream("Szyfr.txt");

        GZIPOutputStream gos = new GZIPOutputStream(new FileOutputStream("Szyfr.gz"));
        int c;
        while((c=fis.read())!=-1) {
            gos.write(c);
        }
        fis.close();
        gos.close();
    }

    public static void decompress() throws IOException {
        GZIPInputStream gis = new GZIPInputStream(new FileInputStream("Szyfr.gz"));
        int c;
        while ((c=gis.read())!=-1) {
            System.out.print((char)c);
        }
        gis.close();
    }

    public static void main(String[] args) throws IOException {

        InputCesarCipher();
        OutputCesarCipher();
        decompress();
    }
}