class EventEmitter {
	constructor() {
		this.eventos = {};
	}

	subscribe(event, cb) {
	  	this.eventos[event] = this.eventos[event] ?? [];
		this.eventos[event].push(cb);

	  	return {
		  	unsubscribe: () => {
				this.eventos[event] = this.eventos[event].filter(fn => fn !== cb);
    		}
	  	};
	}


	emit(event, args = []) {
		if (!this.eventos[event]) {
			return [];
		}
		return this.eventos[event].map(cb => cb(...args));
	}
}
