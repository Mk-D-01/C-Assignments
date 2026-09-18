$html = Get-Content 'index.html' -Raw

# Check if Sample output for exists anywhere in index.html
if ($html -match 'Sample output for') {
    Write-Output "WARNING: 'Sample output for' STILL EXISTS in index.html!"
} else {
    Write-Output "SUCCESS: 'Sample output for' is completely removed from index.html!"
}

# Check Week 1 Question 1 output inside index.html
if ($html -match 'Left Rotation of Array[\s\S]*?outputTemplate: \(dir\) => "PS E:\\\\Codes\\\\C\\\\C Assignments\\\\" \+ dir \+ "\\\\Week1> gcc question1\.c -o a\\nPS E:\\\\Codes\\\\C\\\\C Assignments\\\\" \+ dir \+ "\\\\Week1> \./a\\n([\s\S]*?)"') {
    Write-Output "Verified Week1 Question 1 output:"
    Write-Output $matches[1]
} else {
    Write-Output "Could not match Week1 Question 1 output regex."
}
