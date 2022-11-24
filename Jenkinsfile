pipeline {
    agent any

    stages {
        stage('Fetch') {
            steps {
                git branch: 'main', url: 'https://github.com/aniruddhac13/numbers.git'
                sh "mkdir -p ~/workspace/${JOB_NAME}/${BUILD_NUMBER}"
                sh "cp ~/workspace/${JOB_NAME}/*.c ~/workspace/${JOB_NAME}/*.h ~/workspace/${JOB_NAME}/*.txt ~/workspace/${JOB_NAME}/Makefile ~/workspace/${JOB_NAME}/${BUILD_NUMBER}/"
            }
        }
        stage('Build') {
            steps {
                sh "make libnum.a"
            }
        }
        stage('Test') {
            steps {
                sh "make test"
            }
        }
        stage('Deploy') {
            steps {
                sh "make deploy"
            }
        }
    }
    post {
        always {
            sh "make clean"
        }
    }
}

