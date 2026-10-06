import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.max

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer: StringTokenizer? = null

   
    fun nextToken(): String {
        while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
            val line = reader.readLine() ?: return ""
            tokenizer = StringTokenizer(line)
        }
        return tokenizer!!.nextToken()
    }

    val tStr = nextToken()
    if (tStr.isEmpty()) return
    val t = tStr.toInt()

    val out = StringBuilder()

    for (tc in 0 until t) {
        val n = nextToken().toInt()
        
       
        val a = ArrayList<Long>()
        for (j in 0 until n) {
            a.add(nextToken().toLong())
        }
        a.add(0L)
        
        var ans = 0L
        var i = 0
        
       
        while (i <= n) {
            var sum = 0L
            val tt = ArrayList<Long>()
            var cnt = 0
            
            while (i <= n && a[i] != 0L) {
                tt.add(a[i])
                sum += a[i]
                i++
                cnt++
            }
            
           
            if (cnt > 0) {
                if (cnt % 2 == 0) {
                    ans += 2L * sum
                } else {
                    var mx = 0L
                   
                    var k = 0
                    while (k < tt.size) {
                        mx = max(mx, tt[k])
                        k += 2
                    }
                    ans += 2L * sum - mx
                }
            }
            i++
        }
        out.append(ans).append("\n")
    }
    
    print(out)
}