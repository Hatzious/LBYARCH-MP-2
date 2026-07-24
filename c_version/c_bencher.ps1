$runs = 30
$times = @()

for ($i = 1; $i -le $runs; $i++) {
    $elapsed = Measure-Command {
        Get-Content input.txt | ./c_program.exe | Out-Null
    }
    $ms = $elapsed.TotalMilliseconds
    $times += $ms
    Write-Host "Run ${i}: ${ms} ms"
}

$average = ($times | Measure-Object -Average).Average
Write-Host "`nAverage over $runs runs: ${average} ms"