/**
 * PUM - 1142
 * https://www.urionlinejudge.com.br/judge/pt/problems/view/1142
 * 
 * 'Escreva um programa que leia um valor inteiro N. 
 * Este N é a quantidade de linhas de saída que serão apresentadas na execução do programa.'
 */
var readline = require('readline')
var rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    terminal: false
})

rl.on('line', function(d){
    /**
     * d is object, and when converted to string it will carry endline.
     * Therefore, we use toString and in order trim to deal with it.
     */
    var n = parseInt(d.toString().trim())
    var x = 1
    while (n--) {
        console.log(x++ + ' ' + x++ + ' ' + x++ + ' PUM')
        x++
    }
    rl.close()
})