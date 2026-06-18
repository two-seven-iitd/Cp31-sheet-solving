param(
    [Parameter(Mandatory = $true)]
    [string]$Name
)

$root = $PSScriptRoot
$target = Join-Path $root $Name

if (Test-Path $target) {
    Write-Error "Folder '$Name' already exists at $target"
    exit 1
}

New-Item -ItemType Directory -Path $target | Out-Null

@"
# Good Concepts
"@ | Set-Content -Path (Join-Path $target "Good_Concepts.md") -Encoding utf8

@"
# Good Question
"@ | Set-Content -Path (Join-Path $target "Good_Questions.md") -Encoding utf8

@"
## Pending to Solve/Brainstorm
"@ | Set-Content -Path (Join-Path $target "README.md") -Encoding utf8

Write-Host "Created folder '$Name' with Good_Concepts.md, Good_Questions.md, README.md"
