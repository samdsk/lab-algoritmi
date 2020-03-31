
///////////////////////
// SchedulingJob class
//////////////////////

function SchedulingJob(max, start, end) {
  this.start = start !== undefined ? start : getRandomInt(0, max - 1);
  this.end = end !== undefined ? end : getRandomInt(this.start + 1, max);
  this.taken = false;
}

SchedulingJob.prototype.toString = function () {
  return '(' + this.start.toString() + ' ' + this.end.toString() + ')';
};

SchedulingJob.prototype.isOverlapping = function (anotherJob) {
  if (anotherJob.start < this.start) {
    return anotherJob.end > this.start;
  }
  if (anotherJob.start !== this.start) {
    return this.end > anotherJob.start;
  }
  return true;
};

/////////////////////////


/////////////////////
// JobSet class
///////////////////


function JobSet(slots) {
  this.jobs = null;
  this.slots = slots;
}

JobSet.prototype.constructor = JobSet;
JobSet.prototype.RE = /\(\s*(\d+)\s+(\d+)\s*\)/g;

JobSet.prototype.createJobs = function (n) {
  var i, j;
  if (this.jobs === null) {
    this.jobs = new Array(n);
    for (i = 0; i < this.jobs.length; i += 1) {
      this.jobs[i] = new SchedulingJob(this.slots);
    }
  } else {
    for (j = 1; j < this.jobs.length; j += 1) {
      this.jobs[j].taken = false;
    }
  }
  this.takeJobs();
};


JobSet.prototype.takeJobs = function () {
  var j, t, tt;
  if (this.jobs !== null) {
    this.jobs[0].taken = true;
    for (j = 1; j < this.jobs.length; j += 1) {
      tt = this.takenJobs();
      this.jobs[j].taken = true;
      for (t = 0; t < tt.length; t += 1) {
        if (this.jobs[j].isOverlapping(tt[t])) {
          this.jobs[j].taken = false;
          break;
        }
      }
    }
  }
};

JobSet.prototype.takenJobs = function () {
  return this.jobs.filter(function (each) { return each.taken; });
};

JobSet.prototype.toString = function () {
  var j, s = '';
  for (j = 0; j < this.jobs.length; j += 1) {
    s += this.jobs[j].toString();
  }
  return s;
};

JobSet.prototype.parseJobs = function (s) {
  var newJobs = [], result = JobSet.prototype.RE.exec(s), a, b;
  while (result !== null) {
    a = parseInt(result[1], 10);
    b = parseInt(result[2], 10);
    if (a >= 0 && b <= this.slots && b > a) {
      newJobs.push(new SchedulingJob(this.slots, a, b));
    }
    result = JobSet.prototype.RE.exec(s);
  }
  if (newJobs.length > 0) {
    this.jobs = newJobs;
    this.takeJobs();
  }
};

JobSet.prototype.isTaken = function (jobNumber) {
  if (this.jobs === null) {
    return false;
  }
  return this.jobs[jobNumber].taken;
};

JobSet.prototype.size = function () {
  if (this.jobs === null) {
    return 0;
  }
  return this.jobs.length;
};

JobSet.prototype.sort = function (compareFun) {
  if (this.jobs !== null) {
    this.jobs.sort(compareFun);
  }
};

JobSet.prototype.swap = function (i, j) {
    var t = this.jobs[i];
    this.jobs[i] = this.jobs[j];
    this.jobs[j] = t;
};

///////////////////////
function SlotMorph() {
  Morph.call(this);
}

SlotMorph.prototype = Object.create(Morph.prototype);
SlotMorph.prototype.constructor = SlotMorph;
SlotMorph.prototype.WIDTH = 20;

function JobMorph() {
  Morph.call(this);
}

JobMorph.prototype = Object.create(Morph.prototype);
JobMorph.prototype.constructor = JobMorph;
JobMorph.prototype.HEIGHT = 15;
JobMorph.prototype.BORDER = 2;


///////////////////////
// SchedulerMorph class
///////////////////////

function SchedulerMorph(jj, update) {
  Morph.call(this);
  this.SLOTS = jj.slots;
  this.ARROW_WIDTH = 15;
  this.CAPTION_HEIGHT = 40;
  this.V_OFFSET = 40;
  this.H_OFFSET = 60;
  this.TO_THE_RIGHT = 0;

  
  this.updatable = update !== undefined ? update : false;
  if (this.updatable == true )
  	this.TO_THE_RIGHT = 300;

  this.jobs = jj;
  this.jobs.createJobs(10);
  this.updatable = update !== undefined ? update : false;

  this.setColor(new Color(255, 255, 255));
  this.setPosition(new Point(this.TO_THE_RIGHT + this.H_OFFSET, this.V_OFFSET));
  this.setExtent(new Point(this.SLOTS * SlotMorph.prototype.WIDTH,
                           this.jobs.size() * (JobMorph.prototype.HEIGHT + 2 * JobMorph.prototype.BORDER) + this.CAPTION_HEIGHT));
  
  this.buttonLine = this.position().y;

  var i, x, y, job, t, label, up, down, jobslot, swap;
  for (i = 0; i < this.SLOTS; i += 1) {
    x = new SlotMorph();
    x.setExtent(new Point(SlotMorph.prototype.WIDTH,
                          this.height() - this.CAPTION_HEIGHT));
    x.setPosition(new Point(this.position().x + i * SlotMorph.prototype.WIDTH,
                            this.position().y));
    x.setColor(new Color(238, 238, 238, i % 2 === 0 ? 0.2 : 0.6));
    this.add(x);

    t = new StringMorph(i.toString(), 8);
    t.setPosition(new Point(this.position().x + i * SlotMorph.prototype.WIDTH,
			    x.bottomLeft().y + JobMorph.prototype.BORDER));
    this.add(t);
  }
  
  swap = function (a, b) { // hack for using loop index
	   return function () {
	     jj.swap(a, b);  // a, b closure 
	     updateMorph(jj);
	   };
  };

  for (i = 0; i < jj.size(); i += 1) {

    job = jj.jobs[i];
    y = new JobMorph();
    label = new StringMorph(job.toString(), 10);
    label.setPosition(new Point(this.TO_THE_RIGHT + this.ARROW_WIDTH, this.position().y + JobMorph.prototype.BORDER + 
				(JobMorph.prototype.HEIGHT + 2 * JobMorph.prototype.BORDER) * i));
    this.add(label);

    if (this.updatable) {
      up = new TriggerMorph();
      up.labelString = '\u25b4';
      up.createLabel();
      up.action = swap(i, i - 1); // a, b function parameters

      down = new TriggerMorph();
      down.labelString = '\u25be';
      down.createLabel();
      down.action = swap(i, i + 1);


      up.setPosition(new Point(label.topLeft().x - this.ARROW_WIDTH, label.topLeft().y));
      up.setExtent(new Point(this.ARROW_WIDTH, label.height() / 2 - 1));
      up.setColor(new Color(0, 0, 255, .2));
      if (i !== 0) {
	this.add(up);
      }

      down.setPosition(new Point(label.topLeft().x - this.ARROW_WIDTH, up.bottomLeft().y + 2));
      down.setExtent(new Point(this.ARROW_WIDTH, label.height() / 2 - 1));
      down.setColor(new Color(0, 0, 255, .2));
      if (i !== jj.size() - 1) {
	this.add(down);
      }
    }

    y.setExtent(new Point(SlotMorph.prototype.WIDTH * (job.end - job.start),
                          JobMorph.prototype.HEIGHT));
    y.setPosition(new Point(this.position().x + SlotMorph.prototype.WIDTH * job.start,
                            this.position().y + JobMorph.prototype.BORDER + (JobMorph.prototype.HEIGHT + 2 * JobMorph.prototype.BORDER) * i));
    y.setColor(new Color(0, 0, 255, 0.8));
    jobslot = new Morph();  
    jobslot.setPosition(new Point(this.position().x, y.position().y));
    jobslot.setExtent(new Point(this.SLOTS * SlotMorph.prototype.WIDTH, y.height()));
    jobslot.setColor(new Color(0, 0, 0, 0));
    //    jobslot.acceptsDrops = true;
    //    this.acceptsDrops = false;
    jobslot.add(y);
    this.add(jobslot);
  }
}

SchedulerMorph.prototype = Object.create(Morph.prototype);
SchedulerMorph.prototype.constructor = SchedulerMorph;

SchedulerMorph.prototype.setPosition = function (aPoint) {
  var delta = aPoint.subtract(this.position());
  Morph.prototype.setPosition.call(this, aPoint);
  this.buttonLine += delta.y;
};


SchedulerMorph.prototype.eventCaption = function () {
  var t = new StringMorph('Eventi cui si assiste (in verde): ' + this.jobs.takenJobs().length.toString(),
                          12, 'sans-serif', true);
  t.setColor(new Color(0, 0, 255));
  return t;
};


SchedulerMorph.prototype.orderingMenu = function () {
  var o, ordering, updateLabel, c; 
  o = new TriggerMorph();
  o.labelString = "Scegli il criterio di ordinamento";
  o.setColor(new Color(0, 0, 255, 0.3));
  
  o.setExtent(new Point(o.label.width() + 15, o.label.height() + 10));
  
  o.setPosition(new Point(
	oworld.position().x + 5, 
	oworld.position().y + 30));


  var crStr = new Array(
    "a caso",
    "in base all'ora d'inizio, per primo quello che inizia prima.",
    "in base all'ora d'inizio, per primo quello che inizia piu` tardi.",
    "in base all'ora di fine, per primo quello che finisce prima.",
    "in base all'ora di fine, per primo quello che finisce piu` tardi.",
    "in base alla durata dell'evento, per primo l'evento piu` corto.",
    "in base alla durata dell'evento, per primo l'evento piu` lungo.",
    "in base al numero di sovrapposizioni, per primo l'evento che ha meno sovrapposizioni con gli altri eventi.",
    "in base al numero di sovrapposizioni, per primo l'evento che ha piu` sovrapposizioni con gli altri eventi."
  );

  var cr = new Array(
    "random",
    "start",
    "start-dec",
    "end",
    "end-dec",
    "last",
    "last-dec",
    "over",
    "over-dec"
  );



// DA SISTEMARE
 updateLabel = function (i) {
   console.log( "updatelabel i", i);
   oworld.forAllChildren(function (each) {
     if (each instanceof StringMorph 
	 && (each.text.slice(0,8) == "Eventi o")) {
	 each.destroy();
	 each  = new StringMorph('Eventi ordinati ' + crStr[i] ,
	   12, 'sans-serif', true);
	 each.setColor(new Color(0, 0, 255));
	 oworld.add(each);
	 each.setPosition(new Point(oworld.children[0].position().x, 
	   oworld.children[0].bottomLeft().y - each.height()));
	 each.show();

       }});
  };

  c = new StringMorph('Eventi ordinati ' + crStr[0] ,
                          12, 'sans-serif', true);
  c.setColor(new Color(0, 0, 255));
  this.add(c);
  c.setPosition(new Point(this.position().x, this.bottomLeft().y - c.height()));
  c.show();



  o.action = function () {
    var menu, b;
    b = o;
    menu = new MenuMorph(o);
/*    for (var i = 0; i <= 8; i++ ) {
        console.log("menu i ", i);
	menu.addItem(crStr[i], 
// al momento dell'esecuzione i è già cambiato...
		 function () { updateLabel(i); reorder(cr[i]); },
		 crStr[i]);
    }
    menu.popUpAtHand(o.world());
  };
*/
    menu.addItem(crStr[0], 
		 function () { updateLabel(0); reorder(cr[0]); }, 
		 crStr[0]);
    menu.addItem(crStr[1], 
		 function () { updateLabel(1); reorder(cr[1]); }, 
		 crStr[1]);
    menu.addItem(crStr[2], 
		 function () { updateLabel(2); reorder(cr[2]); }, 
		 crStr[2]);
    menu.addItem(crStr[3], 
		 function () { updateLabel(3); reorder(cr[3]); }, 
		 crStr[3]);
    menu.addItem(crStr[4], 
		 function () { updateLabel(4); reorder(cr[4]); }, 
		 crStr[4]);
    menu.addItem(crStr[5], 
		 function () { updateLabel(5); reorder(cr[5]); }, 
		 crStr[5]);
    menu.addItem(crStr[6], 
		 function () { updateLabel(6); reorder(cr[6]); }, 
		 crStr[6]);
    menu.addItem(crStr[7], 
		 function () { updateLabel(7); reorder(cr[7]); }, 
		 crStr[7]);
    menu.addItem(crStr[8], 
		 function () { updateLabel(8); reorder(cr[8]); }, 
		 crStr[8]);
    menu.popUpAtHand(o.world());
  };

  this.buttonLine += o.height();
  return o;
};

SchedulerMorph.prototype.jobMorphs = function () {
  return this.allChildren().filter(function (each) { 
    return each instanceof JobMorph; });
};

SchedulerMorph.prototype.makeJobsDraggable = function () {
  this.jobMorphs().forEach(function (each) { each.isDraggable = true; });
};

SchedulerMorph.prototype.greedyButton = function () {
  var world = this.root(), o = new TriggerMorph();
  o.labelString = "Determina gli eventi cui partecipare";
 // o.setPosition(new Point(this.position().x + this.width() + JobMorph.prototype.BORDER, 
//			  this.buttonLine + JobMorph.prototype.BORDER));
 o.setPosition(new Point(
         world.position().x + 5, 
         world.position().y + 60 )); 

  o.createLabel();
  o.setExtent(new Point(o.label.width() + 15, o.label.height() + 10));
  o.setColor(new Color(0, 0, 255, 0.2));
  o.action = function () { 
    world.forAllChildren(function (s) {
      var jm, j, c;
      if (s instanceof SchedulerMorph && s.updatable) {
	jm = s.jobMorphs();
	for (j = 0; j < jm.length; j += 1) {
	  jm[j].setColor(s.jobs.isTaken(j) ? new Color(0, 255, 0) : new Color(255, 0, 0));
	}
	c = s.eventCaption();
	c.setPosition(new Point(s.position().x, s.bottomLeft().y ));
	s.add(c);
	c.show();
      }
    });
  };
  this.buttonLine += o.height();
  return o;
};

//////////////////////////////////////


// Returns a random integer between min and max
// Using Math.round() will give you a non-uniform distribution!
function getRandomInt(min, max) {
  return Math.floor(Math.random() * (max - min + 1) + min);
}


function orderByStart(a, b) {
  if (a.start < b.start) {
    return -1;
  }
  if (a.start === b.start) {
    return 0;
  }
  return 1;
}

function orderByRandom() {
  if (Math.random() < 0.5) {
    return -1;
  }
  if (Math.random === 0.5) {
    return 0;
  }
  return 1;
}


function orderByEnd(a, b) {
  if (a.end < b.end) {
    return -1;
  }
  if (a.end === b.end) {
    return 0;
  }
  return 1;
}

function orderByLasting(a, b) {
  var alast = a.end - a.start, blast = b.end - b.start;
  if (alast < blast) {
    return -1;
  }
  if (alast === blast) {
    return 0;
  }
  return 1;
}

function orderByOverlapping(a, b) {
  var aover = 0, bover = 0, i;
  for (i = 0; i < oworld.jobsRefCopy.length; i += 1) {
    if (a !== oworld.jobsRefCopy[i] && a.isOverlapping(oworld.jobsRefCopy[i])) {
      aover += 1;
    }
    if (b !== oworld.jobsRefCopy[i] && b.isOverlapping(oworld.jobsRefCopy[i])) {
      bover += 1;
    }
  }
  if (aover < bover) {
    return -1;
  }
  if (aover === bover) {
    return 0;
  }
  return 1;
}


var orders = { 'start': orderByStart,
	       'start-dec': function (a, b) { return -orderByStart(a, b); },
               'end': orderByEnd,
	       'end-dec': function (a, b) { return -orderByEnd(a, b); },
               'last': orderByLasting,
	       'last-dec': function (a, b) { return -orderByLasting(a, b); },
               'over': orderByOverlapping,
	       'over-dec': function (a, b) { return -orderByOverlapping(a, b); },
               'random': orderByRandom
             };


function reorder(c) {
oworld.forAllChildren(function (each) {
    if (each instanceof SchedulerMorph && each.updatable) {
      each.world().jobsRefCopy = each.jobs.jobs.slice(0);
      each.jobs.sort(orders[c]);
      updateScheduler(each);
    }
  });
}

function updateScheduler(aScheduler) {
  var p, jj, updatable;
  p = aScheduler.position().copy();
  jj = aScheduler.jobs;
  updatable = aScheduler.updatable;
  aScheduler.destroy();
  aScheduler = new SchedulerMorph(jj, updatable);
  aScheduler.setPosition(p);
  oworld.addBack(aScheduler);
}

function newJobString(aString) {
    var jj, us, t;
    jj = new JobSet(SLOTS);
    jj.parseJobs(aString);
    t = w0.allEntryFields()[0];
    t.parent.setExtent(new Point(t.width(), t.height()));
    world.forAllChildren(function (each) { 
      if (each instanceof SchedulerMorph) {
	each.destroy();
      }
    });
    world.add(new SchedulerMorph(jj,false));
    t = w0.allEntryFields()[0];
    t.text = aString;
    t.changed();
    t.drawNew();
    oworld.forAllChildren(function (each) { 
      if (each instanceof SchedulerMorph) {
	each.destroy();
      }
    });
    us = new SchedulerMorph(jj, true);
    oworld.add(us);
    oworld.add(us.orderingMenu());
}

function updateMorph(jj) {
    console.log("updating Morph");
    console.log( "jj", jj.toString() );
    var us;
    oworld.forAllChildren(function (each) { 
      if (each instanceof SchedulerMorph) {
	each.destroy();
      }
    });
    us = new SchedulerMorph(jj, true);
    oworld.add(us);
    oworld.add(us.orderingMenu());
}

// World bootstrap

var w0, world, oworld;
var SLOTS = 24;  

function inputBox(jj) {
  var input, box;
  input = new StringMorph(jj.toString(), 18);
//  input.setColor(new Color(255, 100, 0));
  input.isEditable = true;
  box = new BoxMorph();
  box.setExtent(new Point(input.width(), input.height()));
  box.setColor(new Color(230, 230, 230));

  box.add(input);

  box.reactToEdit = function (s) { newJobString(s.text); };

  return box;
}

window.onload = function () {
  var jobs, scheduler, jobs2, uScheduler, box;
  w0 = new WorldMorph(document.getElementById('world0'), false);
  w0.isDevMode = false;
  w0.setColor(new Color(255, 255, 255));


  world = new WorldMorph(document.getElementById('world1'), false);
  world.isDevMode = false;
  world.setColor(new Color(250, 250, 250));
  //world.acceptsDrops = false;
  jobs = new JobSet(SLOTS);



  scheduler = new SchedulerMorph(jobs);

  ojobs = new JobSet(SLOTS);
  ojobs.jobs = new Array(jobs.jobs.length);
  for (i = 0; i < ojobs.jobs.length; i += 1) {
    ojobs.jobs[i] = new SchedulingJob(ojobs.slots, jobs.jobs[i].start, jobs.jobs[i].end);
  }

 
  //scheduler.makeJobsDraggable();
  world.add(scheduler);
  box = inputBox(jobs);
  box.setPosition(new Point(world.position().x, scheduler.position().y - box.fullBounds().y));
  w0.add(box);


  oworld = new WorldMorph(document.getElementById('world2'), false);
  oworld.isDevMode = false;
  oworld.setColor(new Color(250, 250, 250));

  
  uScheduler = new SchedulerMorph(ojobs, true);
  oworld.add(uScheduler);
  oworld.add(uScheduler.orderingMenu());
  oworld.add(uScheduler.greedyButton());

  window.setInterval(function () { w0.doOneCycle(); world.doOneCycle(); 
				   oworld.doOneCycle();}, 50);
};


/// Local Variables: 
/// mode: js2
/// js2-additional-externs: ("Morph" "Color" "Point" "StringMorph" "MenuMorph" "TriggerMorph" WorldMorph")
/// End: 


