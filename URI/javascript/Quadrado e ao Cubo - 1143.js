/**
 * Quadrado e ao Cubo - 1143
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1143
 */
process.openStdin().addListener("data", function(e) {
    const n = parseInt(e.toString().trim())
    for (var x = 1; x <= n; x++)
        console.log(x + ' ' + x * x + ' ' + x * x * x)
})