$json = Get-Content 'all_41_outputs.json' -Raw | ConvertFrom-Json

# Build PowerShell hashtable for easy replacement
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

# Update sync_lab_data.py content
$pyDictContent = Get-Content 'python_outputs_dict.py' -Raw

$syncPyPath = "sync_lab_data.py"
$syncPyCode = Get-Content $syncPyPath -Raw

# Replace or add AUTHENTIC_OUTPUTS in sync_lab_data.py
if ($syncPyCode -match 'AUTHENTIC_OUTPUTS\s*=\s*\{[\s\S]*?\n\}') {
    $syncPyCode = [regex]::Replace($syncPyCode, 'AUTHENTIC_OUTPUTS\s*=\s*\{[\s\S]*?\n\}', $pyDictContent.Trim())
} else {
    $syncPyCode = $pyDictContent.Trim() + "`n`n" + $syncPyCode
}

# Update line 125 logic in sync_lab_data.py
$oldLinePattern = 'qparts\.append\([\s\S]*?Sample output for[\s\S]*?\)'
$newLineCode = 'exec_out = AUTHENTIC_OUTPUTS.get(week, {}).get(f.name, "")' + "`n" + '        qparts.append(' + "`n" + '            ' + "''{ name: `"' + f.name + '`", title: `"' + title + '`", code: ``' + esc_js(code) + '``, outputTemplate: (dir) => `"PS E:\\Codes\\C\\C Assignments\\\\`" + dir + `"\\\\`" + week + `"> gcc `" + f.name + `" -o a\\nPS E:\\Codes\\C\\C Assignments\\\\`" + dir + `"\\\\`" + week + `"> ./a\\n`" + esc_js(exec_out) + `" }''" + ')'

if ($syncPyCode -match $oldLinePattern) {
    $syncPyCode = [regex]::Replace($syncPyCode, $oldLinePattern, $newLineCode)
}

$syncPyCode | Out-File -FilePath $syncPyPath -Encoding utf8
Write-Output "Updated sync_lab_data.py with AUTHENTIC_OUTPUTS."

# Now update index.html directly using PowerShell
$htmlPath = "index.html"
$html = Get-Content $htmlPath -Raw

$weeks = @('Week1','Week2','Week3','Week4','Week5','Week6','Week7','Week8','Week9','Week10','Week11','Week12','Week13','Week14')
$repoRoot = "Yuvraj_Singh"

function Strip-StudentHeader($c) {
    return [regex]::Replace($c, '(?i)/\*\s*(?:Name-|Roll no\.?|Section-|Course-|Branch-)[\s\S]*?\*/\s*', '')
}

function Esc-Js($s) {
    return $s.Replace('\', '\\').Replace('`', '\`').Replace("`r`n", "\n").Replace("`n", "\n")
}

$manualTitles = @{
    'Week1' = @{ 'question1.c' = 'Left Rotation of Array'; 'question2.c' = 'Minimum Distance Between Two Elements'; 'question3.c' = 'Find Element Occurring Odd Number of Times' }
    'Week2' = @{ 'question1.c' = 'Search an Element in a Sorted Matrix'; 'question2.c' = 'Find Row with Maximum Number of 1s'; 'question3.c' = 'Rotate Matrix in Clockwise Direction' }
    'Week3' = @{ 'question1.c' = 'Stack Operations Using Array'; 'question2.c' = 'Check for Balanced Parentheses'; 'question3.c' = 'Longest Valid Parentheses Substring' }
    'Week4' = @{ 'question1.c' = 'Reverse String Using Stack'; 'question2.c' = 'Implement Two Stacks in One Array'; 'question3.c' = 'Evaluation of Postfix Expression' }
    'Week5' = @{ 'question1.c' = 'Queue Operations Using Array'; 'question2.c' = 'Reverse a Queue'; 'question3.c' = 'Deque Operations' }
    'Week6' = @{ 'question1.c' = 'Implement Stack Using One Queue'; 'question2.c' = 'Implement Queue Using Two Stacks'; 'question3.c' = 'Circular Queue Operations' }
    'Week7' = @{ 'question1.c' = 'Linked List Operations'; 'question2.c' = 'Queue Operations Using Linked List'; 'question3.c' = 'Stack Operations Using Linked List' }
    'Week8' = @{ 'question1.c' = 'Doubly Linked List Operations'; 'question2.c' = 'Reverse a Doubly Linked List'; 'question3.c' = 'Remove Duplicates from Doubly Linked List' }
    'Week9' = @{ 'question1.c' = 'Circular Linked List Operations'; 'question2.c' = 'Concatenate Two Circular Linked Lists'; 'question3.c' = 'Split a Circular Linked List' }
    'Week10' = @{ 'question1.c' = 'Split Linked List into Odd and Even Nodes'; 'question2.c' = 'Find Nth Element from the End'; 'question3.c' = 'Reverse a Linked List in Single Pass' }
    'Week11' = @{ 'question1.c' = 'Tree Height and Size'; 'question2.c' = 'Tree Traversal Techniques'; 'question3.c' = 'Infix to Postfix Conversion' }
    'Week12' = @{ 'question1.c' = 'Binary Search Tree Operations'; 'question2.c' = 'Construct a Balanced BST'; 'question3.c' = 'Find Level with Maximum Number of Nodes' }
    'Week13' = @{ 'question1.c' = 'Priority Queue Using Max Heap'; 'question2.c' = 'Check if an Array Represents a Heap'; 'question3.c' = 'Find Kth Largest Element Using Heap' }
    'Week14' = @{ 'question1.c' = 'Memory Representation Analysis for Graphs'; 'question2.c' = 'Friendship Analysis Using Adjacency Matrix' }
}

$parts = @()
foreach ($week in $weeks) {
    $dir = Join-Path $repoRoot $week
    if (-not (Test-Path $dir)) { continue }
    
    $qfiles = Get-ChildItem -Path $dir -Filter "question*.c" | Sort-Object { [int]($_.BaseName -replace 'question', '') }
    $qparts = @()
    foreach ($f in $qfiles) {
        $rawCode = Get-Content $f.FullName -Raw -Encoding utf8
        $cleanCode = Strip-StudentHeader $rawCode
        $title = $manualTitles[$week][$f.Name]
        if (-not $title) { $title = "Question " + ($f.BaseName -replace 'question', '') }
        
        $execOut = $map[$week][$f.Name]
        $escCode = Esc-Js $cleanCode
        $escOut = Esc-Js $execOut
        
        $qparts += '{ name: "' + $f.Name + '", title: "' + $title + '", code: `' + $escCode + '`, outputTemplate: (dir) => "PS E:\\Codes\\C\\C Assignments\\" + dir + "\\' + $week + '> gcc ' + $f.Name + ' -o a\nPS E:\\Codes\\C\\C Assignments\\" + dir + "\\' + $week + '> ./a\n' + $escOut + '" }'
    }
    $parts += '"' + $week + '": { title: "' + $week + '", questions: [' + ($qparts -join ",`n                    ") + '] }'
}

$outLabData = "const labData = {`n            " + ($parts -join ",`n            ") + "`n        };`n`n        let selectedWeek = `"Week1`";"

$pattern = '(?s)const labData = \{.*?\n\s*\};\s*let selectedWeek = "Week1";'
if ($html -match $pattern) {
    $newHtml = [regex]::Replace($html, $pattern, $outLabData)
    $newHtml | Out-File -FilePath $htmlPath -Encoding utf8
    Write-Output "Successfully updated index.html with all authentic outputs!"
} else {
    Write-Output "ERROR: Could not find labData pattern in index.html"
}
