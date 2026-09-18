const fs = require('fs');
const path = require('path');

const workspace = __dirname;
const htmlPath = path.join(workspace, 'index.html');
const repoRoot = path.join(workspace, 'Yuvraj_Singh');

const weeks = [
  'Week1', 'Week2', 'Week3', 'Week4', 'Week5', 'Week6',
  'Week7', 'Week8', 'Week9', 'Week10', 'Week11', 'Week12', 'Week13', 'Week14'
];

function stripStudentHeader(code) {
  return code.replace(/\/\*\s*(?:Name-|Roll no\.?|Section-|Course-|Branch-)[\s\S]*?\*\/\s*/gi, '');
}

function escapeCodeForJsString(str) {
  return stripStudentHeader(str)
    .replace(/\\/g, '\\\\')
    .replace(/`/g, '\\`')
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

const manualTitles = {
  Week1: {
    'question1.c': 'Left Rotation of Array',
    'question2.c': 'Minimum Distance Between Two Elements',
    'question3.c': 'Find Element Occurring Odd Number of Times'
  },
  Week2: {
    'question1.c': 'Search an Element in a Sorted Matrix',
    'question2.c': 'Find Row with Maximum Number of 1s',
    'question3.c': 'Rotate Matrix in Clockwise Direction'
  },
  Week3: {
    'question1.c': 'Stack Operations Using Array',
    'question2.c': 'Check for Balanced Parentheses',
    'question3.c': 'Longest Valid Parentheses Substring'
  },
  Week4: {
    'question1.c': 'Reverse String Using Stack',
    'question2.c': 'Implement Two Stacks in One Array',
    'question3.c': 'Evaluation of Postfix Expression'
  },
  Week5: {
    'question1.c': 'Queue Operations Using Array',
    'question2.c': 'Reverse a Queue',
    'question3.c': 'Deque Operations'
  },
  Week6: {
    'question1.c': 'Implement Stack Using One Queue',
    'question2.c': 'Implement Queue Using Two Stacks',
    'question3.c': 'Circular Queue Operations'
  },
  Week7: {
    'question1.c': 'Linked List Operations',
    'question2.c': 'Queue Operations Using Linked List',
    'question3.c': 'Stack Operations Using Linked List'
  },
  Week8: {
    'question1.c': 'Doubly Linked List Operations',
    'question2.c': 'Reverse a Doubly Linked List',
    'question3.c': 'Remove Duplicates from Doubly Linked List'
  },
  Week9: {
    'question1.c': 'Circular Linked List Operations',
    'question2.c': 'Concatenate Two Circular Linked Lists',
    'question3.c': 'Split a Circular Linked List'
  },
  Week10: {
    'question1.c': 'Split Linked List into Odd and Even Nodes',
    'question2.c': 'Find Nth Element from the End',
    'question3.c': 'Reverse a Linked List in Single Pass'
  },
  Week11: {
    'question1.c': 'Tree Height and Size',
    'question2.c': 'Tree Traversal Techniques',
    'question3.c': 'Infix to Postfix Conversion'
  },
  Week12: {
    'question1.c': 'Binary Search Tree Operations',
    'question2.c': 'Construct a Balanced BST',
    'question3.c': 'Find Level with Maximum Number of Nodes'
  },
  Week13: {
    'question1.c': 'Priority Queue Using Max Heap',
    'question2.c': 'Check if an Array Represents a Heap',
    'question3.c': 'Find Kth Largest Element Using Heap'
  },
  Week14: {
    'question1.c': 'Memory Representation Analysis for Graphs',
    'question2.c': 'Friendship Analysis Using Adjacency Matrix'
  }
};

function inferQuestionTitle(code, fileName, week) {
  const manual = manualTitles[week];
  if (manual && manual[fileName]) {
    return manual[fileName];
  }

  const cleaned = stripStudentHeader(code)
    .replace(/\/\/.*$/gm, '')
    .replace(/\/\*[\s\S]*?\*\//g, '');

  const functionRegex = /(?:[A-Za-z_][A-Za-z0-9_\s\*\[\]]+)\s+([A-Za-z_][A-Za-z0-9_]*)\s*\([^;]*\)\s*\{/g;
  const matches = [];
  let m;

  while ((m = functionRegex.exec(cleaned)) !== null) {
    const name = m[1];
    if (!['main', 'printf', 'scanf', 'fgets', 'malloc', 'free', 'strlen', 'strcmp', 'strtok', 'isdigit', 'tolower', 'toupper'].includes(name.toLowerCase())) {
      matches.push(name);
    }
  }

  if (matches.length > 0) {
    const title = matches[0]
      .replace(/([a-z0-9])([A-Z])/g, '$1 $2')
      .replace(/_/g, ' ')
      .trim();

    return title
      .split(/\s+/)
      .map(part => part.charAt(0).toUpperCase() + part.slice(1).toLowerCase())
      .join(' ');
  }

  const qNum = fileName.replace(/question(\d+)\.c/i, '$1');
  return `Question ${qNum}`;
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
      const title = inferQuestionTitle(code, file, week);

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
  const outputsJsonPath = path.join(workspace, 'all_41_outputs.json');
  const outputsData = fs.existsSync(outputsJsonPath) ? JSON.parse(fs.readFileSync(outputsJsonPath, 'utf8')) : [];
  const outputsMap = {};
  outputsData.forEach(item => {
    if (!outputsMap[item.Week]) outputsMap[item.Week] = {};
    const lines = item.Content.split('\n');
    outputsMap[item.Week][item.File] = lines.slice(2).join('\n').trim();
  });

  const labData = generateLabData();
  const weeksText = Object.entries(labData)
    .map(([week, data]) => {
      const questionsText = data.questions
        .map((q, index) => {
          const rawOut = (outputsMap[week] && outputsMap[week][q.name]) || '';
          const escOut = rawOut.replace(/\\/g, '\\\\').replace(/`/g, '\\`').replace(/\r\n/g, '\\n').replace(/\n/g, '\\n');
          const outputTemplate = `outputTemplate: (dir) => "PS E:\\\\Codes\\\\C\\\\C Assignments\\\\" + dir + "\\\\${week}> gcc ${q.name} -o a\\nPS E:\\\\Codes\\\\C\\\\C Assignments\\\\" + dir + "\\\\${week}> ./a\\n${escOut}"`;
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
for (const week of weeks) {
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
console.log('Updated all week code blocks in index.html from repo source files.');
