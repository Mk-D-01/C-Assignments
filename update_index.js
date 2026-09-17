const fs = require('fs');
const path = require('path');

const workspace = __dirname;
const htmlPath = path.join(workspace, 'index.html');
const repoRoot = path.join(workspace, 'Yuvraj_Singh');

const weeks = [
  'Week1', 'Week2', 'Week3', 'Week4', 'Week5', 'Week6',
  'Week7', 'Week8', 'Week9', 'Week10', 'Week11', 'Week12', 'Week13', 'Week14'
];

function escapeCodeForJsString(str) {
  return str
    .replace(/\\/g, '\\\\')
    .replace(/`/g, '\\`')
    .replace(/\$\{/g, '\\${')
    .replace(/\r\n/g, '\n')
    .replace(/\n/g, '\\n');
}

function replaceSourceCode(block, week) {
  const weekDir = path.join(repoRoot, week);
  const questionFiles = fs.readdirSync(weekDir)
    .filter(f => /^question\d+\.c$/i.test(f))
    .sort((a, b) => parseInt(a.match(/\d+/)[0], 10) - parseInt(b.match(/\d+/)[0], 10));

  for (const file of questionFiles) {
    const code = escapeCodeForJsString(fs.readFileSync(path.join(weekDir, file), 'utf8'));
    const questionPattern = new RegExp(
      '(name: "' + file + '",\\s+title:[\\s\\S]*?\\s+code: )`[\\s\\S]*?`'
    );
    block = block.replace(questionPattern, `$1\`${code}\``);
  }

  return block;
}

function generateLabData() {
  const labData = {};

  for (const week of weeks) {
    const weekDir = path.join(repoRoot, week);
    if (!fs.existsSync(weekDir)) continue;

    const questionFiles = fs.readdirSync(weekDir)
      .filter(f => /^question\d+\.c$/i.test(f))
      .sort((a, b) => {
        const na = parseInt(a.match(/\d+/)[0], 10);
        const nb = parseInt(b.match(/\d+/)[0], 10);
        return na - nb;
      });

    const questions = questionFiles.map(file => {
      const fullPath = path.join(weekDir, file);
      const code = fs.readFileSync(fullPath, 'utf8');
      const title = `Question ${file.replace(/question(\d+)\.c/i, '$1')}`;

      return {
        name: file,
        title,
        code: `\`${escapeCodeForJsString(code)}\``,
        outputTemplate: '(dir) => ""'
      };
    });

    labData[week] = {
      title: week.replace(/(\d+)/, ' $1'),
      questions
    };
  }

  return labData;
}

function buildDataBlob() {
  const labData = generateLabData();
  const weeksText = Object.entries(labData)
    .map(([week, data]) => {
      const questionsText = data.questions
        .map((q, index) => {
          const outputTemplate = `outputTemplate: (dir) => \`PS E:\\\\Codes\\\\C\\\\C Assignments\\\\${dir}\\\\${week}> gcc ${q.name} -o a\\nPS E:\\\\Codes\\\\C\\\\C Assignments\\\\${dir}\\\\${week}> ./a\\nSample Run\\nQuestion ${index + 1}\``;
          return `\n                    {\n                        name: "${q.name}",\n                        title: "${q.title}",\n                        code: ${q.code},\n                        ${outputTemplate}\n                    }`;
        })
        .join(',');

      return `\n            "${week}": {\n                title: "${week}",\n                questions: [${questionsText}\n                ]\n            }`;
    })
    .join(',');

  return `const labData = {${weeksText}\n        };`;
}

const html = fs.readFileSync(htmlPath, 'utf8');
const marker = 'const labData = {';
const start = html.indexOf(marker);
if (start === -1) {
  throw new Error('Could not find labData marker in index.html');
}

const nextStart = html.indexOf('};', start);
if (nextStart === -1) {
  throw new Error('Could not find end of labData object in index.html');
}

let dataBlock = html.slice(start, nextStart + 2);
for (const week of weeks.slice(6)) {
  const weekStart = dataBlock.indexOf(`"${week}":`);
  if (weekStart === -1) continue;

  const nextWeekStart = weeks
    .slice(weeks.indexOf(week) + 1)
    .map(nextWeek => dataBlock.indexOf(`"${nextWeek}":`, weekStart + 1))
    .find(index => index !== -1);
  const weekEnd = nextWeekStart === undefined ? dataBlock.length : nextWeekStart;
  const weekBlock = replaceSourceCode(dataBlock.slice(weekStart, weekEnd), week);
  dataBlock = dataBlock.slice(0, weekStart) + weekBlock + dataBlock.slice(weekEnd);
}

const updated = html.slice(0, start) + dataBlock + html.slice(nextStart + 2);
fs.writeFileSync(htmlPath, updated);
console.log('Updated Week 7-14 code in index.html from repo source files.');
