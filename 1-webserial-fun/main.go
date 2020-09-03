package main

import (
	"fmt"
	"log"
	"net/http"
)

const addr = ":8090"

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintln(w, js)
	})

	log.Printf("Listening on addr: %s", addr)
	http.ListenAndServe(addr, nil)
}
