$json = Get-Content 'all_41_outputs.json' -Raw | ConvertFrom-Json

$map = @{}
foreach ($item in $json) {
    $week = $item.Week
    $fname = $item.File
    $lines = $item.Content -split "`n"
    $body = if ($lines.Length -gt 2) { ($lines[2..($lines.Length - 1)] -join "`n").Trim() } else { "" }
    
    if (-not $map.ContainsKey($week)) {
        $map[$week] = @{}
    }
    $map[$week][$fname] = $body
}

# Generate Python code representation for AUTHENTIC_OUTPUTS
$pyDictLines = @("AUTHENTIC_OUTPUTS = {")
$weekKeys = $map.Keys | Sort-Object { [int]($_ -replace 'Week', '') }

foreach ($w in $weekKeys) {
    $pyDictLines += "    '$w': {"
    $fileKeys = $map[$w].Keys | Sort-Object { [int]($_ -replace 'question|\.c', '') }
    $fEntries = @()
    foreach ($f in $fileKeys) {
        $val = $map[$w][$f]
        # Escape for Python string literal
        $escapedVal = $val -replace '\\', '\\\\' -replace "'", "\'" -replace "`r`n", "\n" -replace "`n", "\n"
        $fEntries += "        '$f': '$escapedVal'"
    }
    $pyDictLines += ($fEntries -join ",`n")
    $pyDictLines += "    },"
}
$pyDictLines += "}"

$pyDictText = $pyDictLines -join "`n"
$pyDictText | Out-File -FilePath "python_outputs_dict.py" -Encoding utf8
Write-Output "Generated python_outputs_dict.py successfully."
