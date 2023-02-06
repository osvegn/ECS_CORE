#!/usr/bin/env groovy
pipeline {
    agent any
    stages {
        stage('Hello') {
            steps {
                echo "hello world"
            }
        }
        stage('Is there a makefile ?') {
            shell('find Makefile')
        }
        stage('No dockerfile ?') {
            shell('find Dockerfile')
        }
    }
}
